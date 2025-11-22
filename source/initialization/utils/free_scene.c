/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 23:40:49 by alisharu          #+#    #+#             */
/*   Updated: 2025/11/20 14:56:52 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->ambient)
	{
		if (scene->ambient->color)
			free(scene->ambient->color);
		free(scene->ambient);
	}
	ft_lstclear(&scene->camera, free_camera);
	ft_lstclear(&scene->lights, free_light);
	ft_lstclear(&scene->objects, free_object);
	free(scene);
}

void	free_scene_inits(t_scene *scene, char **line, char **map)
{
	if (scene)
		free_scene(scene);
	if (line)
		ft_free_matrix(line);
	if (map)
		ft_free_matrix(map);
}
