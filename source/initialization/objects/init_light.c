/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:32:03 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/30 10:52:25 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

void	init_light(t_scene *scene, char **line, char **map)
{
	t_list	*node;
	t_light	*light;

	light = ft_calloc(1, sizeof(t_light));
	if (!light)
	{
		free_scene_inits(scene, line, map);
		error_handling(MALLOC_ERROR);
	}
	light->position = init_vector(line[1]);
	light->brightness_ratio = ft_atof(line[2]);
	light->color = parse_color(line[3]);
	if (!light->position || !light->color)
	{
		free(light);
		free_scene_inits(scene, line, map);
		error_handling(MALLOC_ERROR);
	}
	node = ft_lstnew(light);
	if (!node)
	{
		free(light);
		free_scene_inits(scene, line, map);
		error_handling(MALLOC_ERROR);
	}
	ft_lstadd_back(&scene->lights, node);
}
