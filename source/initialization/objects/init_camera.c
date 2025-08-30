/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:31:55 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/29 14:01:29 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

t_vector	*init_vector(char *line)
{
	t_vector	*vector;
	char		**matrix_vector;

	if (!line)
		return (NULL);
	vector = ft_calloc(1, sizeof(t_vector));
	if (!vector)
		return (NULL);
	matrix_vector = ft_split(line, ',');
	if (!matrix_vector || !matrix_vector[0] || !matrix_vector[1]
		|| !matrix_vector[2])
		return (NULL);
	vector->x = ft_atof(matrix_vector[0]);
	vector->y = ft_atof(matrix_vector[1]);
	vector->z = ft_atof(matrix_vector[2]);
	ft_free_matrix(matrix_vector);
	matrix_vector = NULL;
	return (vector);
}

void	init_camera(t_scene *scene, char **line, char **map)
{
	t_list		*node;
	t_camera	*camera;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
	{
		free_scene_inits(scene, line, map);
		error_handling(MALLOC_ERROR);
	}
	camera->position = init_vector(line[1]);
	camera->direction = init_vector(line[2]);
	camera->field_of_view = ft_atoi(line[3]);
	if (!camera->position || !camera->direction)
	{
		free(camera);
		free_scene_inits(scene, line, map);
		error_handling(MALLOC_ERROR);
	}
	node = ft_lstnew(camera);
	if (!node)
	{
		free(camera);
		free_scene_inits(scene, line, map);
		error_handling(MALLOC_ERROR);
	}
	ft_lstadd_back(&scene->camera, node);
}
