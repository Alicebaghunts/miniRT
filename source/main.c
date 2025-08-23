/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:36:16 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/23 21:57:51 by alicebaghun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	is_valid_float(const char *str)
{
	int	i;
	int	has_dot;

	if (!str || !*str)
		return (0);
	i = 0;
	has_dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 0 && (ft_isdigit(str[i - 1]) || (has_dot && i > 1)))
		return (1);
	else
		return (0);
}

int	is_in_range_float(const char *str, float min, float max)
{
	float	val;

	if (!str)
		return (0);
	val = ft_atof(str);
	if (val < min || val > max)
		return (0);
	return (1);
}

int	is_valid_ambient(char **line)
{
	char	**rgb;
	int		i;

	if (!line || ft_strcmp(line[0], "A") != 0)
		return (0);
	if (!line[1] || !line[2] || line[3])
		return (0);
	if (!is_valid_float(line[1]) || !is_in_range_float(line[1], 0.0, 1.0))
		return (0);
	rgb = ft_split(line[2], ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (0);
	i = -1;
	while (++i < 3)
	{
		if (!is_valid_int(rgb[i]) || !is_in_range_int(rgb[i], 0, 255))
			return (ft_free_matrix(rgb), 0);
	}
	ft_free_matrix(rgb);
	return (1);
}

void	validate_ambient(char **map, char **line)
{
	if (!is_valid_ambient(line))
	{
		ft_free_matrix(line);
		ft_free_matrix(map);
		error_handling(INVALID_MAP);
	}
}

void	validate_map_line(char **map, char **line)
{
	if (!line || !line[0])
		return ;
	if (ft_strcmp(line[0], "A") == 0)
		validate_ambient(map, line);
	else if (ft_strcmp(line[0], "C") == 0)
		validate_camera(map, line);
	else if (ft_strcmp(line[0], "L") == 0)
		validate_light(map, line);
	else if (ft_strcmp(line[0], "sp") == 0)
		validate_sphere(map, line);
	else if (ft_strcmp(line[0], "pl") == 0)
		validate_plane(map, line);
	else if (ft_strcmp(line[0], "cy") == 0)
		validate_cylinder(map, line);
	else
	{
		ft_putstr_fd("Unknown identifier: ", 2);
		ft_putstr_fd(line[0], 2);
		ft_putchar_fd('\n', 2);
		ft_free_matrix(line);
		ft_free_matrix(map);
		error_handling(INVALID_MAP);
	}
}

void	validate_map(char **map)
{
	char	**split_line;
	int		i;

	i = -1;
	while (map[++i] != NULL)
	{
		split_line = ft_split(map[i], " ");
		if (!split_line)
			error_handling(MALLOC_ERROR);
		validate_map_line(map, split_line);
		ft_free_matrix(split_line);
	}
}
int	main(int argc, char **argv)
{
	int		fd;
	char	**map_array;

	if (argc != 2)
		error_handling(INVALID_ARGUMENT);
	fd = check_and_open_map_file(argv[1]);
	map_array = read_in_map_file(fd);
	validate_map(map_array);
}
