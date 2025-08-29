/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:33:32 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/28 21:57:41 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	error_handling(int num)
{
	if (num == 1)
		ft_putstr_fd("Error: Invalid argument\n", 2);
	else if (num == 2)
		ft_putstr_fd("Error: Invalid path\n", 2);
	else if (num == 3)
		ft_putstr_fd("Error: Failed to open file\n", 2);
	else if (num == 4)
		ft_putstr_fd("Error: Invalid map\n", 2);
	else if (num == 5)
		ft_putstr_fd("Error: Failed to malloc\n", 2);
	exit(num);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;
	t_camera *camera;

	int		fd;
	char	**map_array;

	if (argc != 2)
		error_handling(INVALID_ARGUMENT);
	fd = check_and_open_map_file(argv[1]);
	map_array = read_in_map_file(fd);
	validate_map(map_array);
	scene = initialize_scene(map_array);
	camera = scene->camera->content;
	printf("CAMERA position x-> %f\n", camera->position->x);
	printf("CAMERA position y-> %f\n", camera->position->y);
	printf("CAMERA position z-> %f\n", camera->position->z);
	printf("CAMERA direction x-> %f\n", camera->direction->x);
	printf("CAMERA direction y-> %f\n", camera->direction->y);
	printf("CAMERA direction z-> %f\n", camera->direction->z);
	printf("camera field_of_view -> %d\n", camera->field_of_view);
}
