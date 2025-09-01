/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:31:40 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/01 16:11:15 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

void	free_sphere(t_sphere *sphere)
{
	if (!sphere)
		return ;
	if (sphere->position)
		free(sphere->position);
	if (sphere->color)
		free(sphere->color);
	free(sphere);
}

void	free_plane(t_plane *plane)
{
	if (!plane)
		return ;
	if (plane->position)
		free(plane->position);
	if (plane->normal)
		free(plane->normal);
	if (plane->color)
		free(plane->color);
	free(plane);
}

void	free_cylinder(t_cylinder *cylinder)
{
	if (!cylinder)
		return ;
	if (cylinder->position)
		free(cylinder->position);
	if (cylinder->direction)
		free(cylinder->direction);
	if (cylinder->color)
		free(cylinder->color);
	free(cylinder);
}

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

void	free_object(void *content)
{
	t_object	*object;

	object = (t_object *)content;
	if (!object)
		return ;
	if (object->data)
	{
		if (object->type == 'c')
			free_cylinder(object->data->cylinder);
		else if (object->type == 's')
			free_sphere(object->data->sphere);
		else if (object->type == 'p')
			free_plane(object->data->plane);
		free(object->data);
	}
	free(object);
}
