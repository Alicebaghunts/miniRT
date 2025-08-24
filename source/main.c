/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:36:16 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/24 16:38:15 by alicebaghun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

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
