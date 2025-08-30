/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:33:32 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/30 10:55:03 by alisharu         ###   ########.fr       */
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
	t_list	*node;
	t_light	*light;
	int		fd;
	char	**map_array;

	if (argc != 2)
		error_handling(INVALID_ARGUMENT);
	fd = check_and_open_map_file(argv[1]);
	map_array = read_in_map_file(fd);
	validate_map(map_array);
	scene = initialize_scene(map_array);
	node = scene->lights;
	while (node)
	{
		light = node->content;
		printf("light position x-> %f\n", light->position->x);
		printf("light position y-> %f\n", light->position->y);
		printf("light position z-> %f\n", light->position->z);
		printf("light color red-> %d\n", light->color->red);
		printf("light color green-> %d\n", light->color->green);
		printf("light color blue-> %d\n", light->color->blue);
		printf("light ratio -> %f\n", light->brightness_ratio);
		printf("----------\n");
		node = node->next;
	}
}
