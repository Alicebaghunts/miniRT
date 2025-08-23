/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:36:16 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/23 20:55:38 by alicebaghun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void validate_map_line();

void	validate_map(char **map)
{
	char	**split_line;
	int		i;

	i = 0;
	while (split_line[i] != NULL)
	{
		split_line = ft_split(split_line[i], " ");
		validate_map_line(split_line);
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
