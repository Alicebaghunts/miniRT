/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:25:06 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/24 19:02:12 by alicebaghun      ###   ########.fr       */
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

int	is_valid_position_vector(char *line)
{
	char	**pos_vector;
	int		i;

	pos_vector = ft_split(line, ',');
	if (!pos_vector || !pos_vector[0] || !pos_vector[1] || !pos_vector[2]
		|| pos_vector[3])
		return (ft_free_matrix(pos_vector), 0);
	i = -1;
	while (++i < 3)
	{
		if (!is_valid_float(pos_vector[i]))
			return (ft_free_matrix(pos_vector), 0);
	}
	ft_free_matrix(pos_vector);
	return (1);
}

int	is_valid_rgb_argument(char *line)
{
	char	**rgb;
	int		i;

	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (ft_free_matrix(rgb), 0);
	i = -1;
	while (++i < 3)
	{
		if (!is_valid_number(rgb[i]) || !is_in_range_int(rgb[i], 0, 255))
			return (ft_free_matrix(rgb), 0);
	}
	ft_free_matrix(rgb);
	return (1);
}

int	is_valid_direction_vector(char *line)
{
	char	**dir_vector;
	int		i;

	dir_vector = ft_split(line, ',');
	if (!dir_vector || !dir_vector[0] || !dir_vector[1] || !dir_vector[2]
		|| dir_vector[3])
		return (ft_free_matrix(dir_vector), 0);
	i = -1;
	while (++i < 3)
	{
		if (!is_valid_float(dir_vector[i]) || !is_in_range_float(dir_vector[i],
				-1.0, 1.0))
			return (ft_free_matrix(dir_vector), 0);
	}
	ft_free_matrix(dir_vector);
	return (1);
}

int	is_valid_brightness_ratio(char *line)
{
	if (!is_valid_float(line) || !is_in_range_float(line, 0.0, 1.0))
		return (0);
	return (1);
}

int	is_valid_fov(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '+')
		i++;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	if (!is_in_range_int(line, 0, 180))
		return (0);
	return (1);
}

int	is_valid_diameter(const char *line)
{
	float	val;
	int		i;

	if (!line)
		return (0);
	i = 0;
	if (line[i] == '+')
		i++;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != '.')
			return (0);
		i++;
	}
	val = ft_atof(line);
	if (val < 0)
		return (0);
	return (1);
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

int	is_in_range_int(const char *str, float min, float max)
{
	int	val;

	if (!str)
		return (0);
	val = ft_atoi(str);
	if (val < min || val > max)
		return (0);
	return (1);
}

int	is_valid_number(char *num_str)
{
	int	i;

	i = 0;
	if (!num_str)
		return (0);
	if (num_str[0] == '-' || num_str[0] == '+')
		i++;
	while (num_str[i])
	{
		if (!ft_isdigit(num_str[i]))
			return (0);
		i++;
	}
	return (1);
}
