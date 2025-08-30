/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:29:37 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/30 10:52:37 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

void	free_light(void *content)
{
	t_light	*light;

	light = (t_light *)content;
	if (!light)
		return ;
	if (light->position)
		free(light->position);
	if (light->color)
		free(light->color);
	free(light);
}

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
	if (scene->camera)
		free(scene->camera);
	ft_lstclear(&scene->lights, free_light);
	ft_lstclear(&scene->objects, free);
	free(scene);
}

void	free_scene_inits(t_scene *scene, char **line, char **map)
{
	if (scene)
		free_scene(scene);
	if (line)
	{
		ft_free_matrix(line);
		line = NULL;
	}
	if (map)
	{
		ft_free_matrix(map);
		map = NULL;
	}
}

void	fill_scene_with_line(t_scene *scene, char **line, char **map)
{
	if (!scene || !line || !line[0])
		return ;
	if (ft_strcmp(line[0], "A") == 0)
		init_ambient(scene, line, map);
	else if (ft_strcmp(line[0], "C") == 0)
		init_camera(scene, line, map);
	else if (ft_strcmp(line[0], "L") == 0)
		init_light(scene, line, map);
	// else if (ft_strcmp(line[0], "sp") == 0)
	// 	init_sphere(scene, line, map);
	// else if (ft_strcmp(line[0], "pl") == 0)
	// 	init_plane(scene, line, map);
	// else if (ft_strcmp(line[0], "cy") == 0)
	// 	init_cylinder(scene, line, map);
}

t_scene	*initialize_scene(char **map)
{
	t_scene	*scene;
	char	**split_line;
	int		i;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		error_handling(MALLOC_ERROR);
	i = -1;
	while (map[++i])
	{
		split_line = ft_split(map[i], ' ');
		if (!split_line)
		{
			free_scene_inits(scene, split_line, map);
			error_handling(MALLOC_ERROR);
		}
		fill_scene_with_line(scene, split_line, map);
		ft_free_matrix(split_line);
	}
	return (scene);
}
