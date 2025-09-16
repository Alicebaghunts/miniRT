/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:23:03 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/16 16:09:23 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

double	vector_length(t_vector vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y + vector.z
			* vector.z));
}

void	normalize_vectors(t_scene *scene)
{
	t_list		*node;
	t_object	*objects;

	if (!scene)
		return ;
	node = scene->camera;
	while (node)
	{
		if (node->content && ((t_camera *)node->content)->direction)
			*((t_camera *)node->content)->direction
				= normalize(*((t_camera *)node->content)->direction);
		node = node->next;
	}
	node = scene->objects;
	while (node)
	{
		objects = (t_object *)node->content;
		if (objects)
		{
			if (objects->type == 'p' && objects->data->plane
				&& objects->data->plane->normal)
				*objects->data->plane->normal = normalize(*objects->data->plane->normal);
			else if (objects->type == 'c' && objects->data->cylinder
				&& objects->data->cylinder->direction)
				*objects->data->cylinder->direction
					= normalize(*objects->data->cylinder->direction);
		}
		node = node->next;
	}
}

t_vector	normalize(t_vector vector)
{
	double		length;
	t_vector	result;

	length = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z
			* vector.z);
	if (length == 0)
	{
		result.x = 0;
		result.y = 0;
		result.z = 0;
		return (result);
	}
	result.x = vector.x / length;
	result.y = vector.y / length;
	result.z = vector.z / length;
	return (result);
}

t_vector	sphere_normal(t_sphere *sphere, t_vector hit_point)
{
	t_vector	normal;

	normal.x = hit_point.x - sphere->position->x;
	normal.y = hit_point.y - sphere->position->y;
	normal.z = hit_point.z - sphere->position->z;
	return (normalize(normal));
}

t_vector	cylinder_normal(t_cylinder *cyl, t_vector hit_point)
{
	t_vector	base_to_hit;
	double		projection;
	t_vector	closest_point_on_axis;
	t_vector	normal;

	base_to_hit.x = hit_point.x - cyl->position->x;
	base_to_hit.y = hit_point.y - cyl->position->y;
	base_to_hit.z = hit_point.z - cyl->position->z;
	projection = base_to_hit.x * cyl->direction->x + base_to_hit.y
		* cyl->direction->y + base_to_hit.z * cyl->direction->z;
	closest_point_on_axis.x = cyl->position->x + cyl->direction->x * projection;
	closest_point_on_axis.y = cyl->position->y + cyl->direction->y * projection;
	closest_point_on_axis.z = cyl->position->z + cyl->direction->z * projection;
	normal.x = hit_point.x - closest_point_on_axis.x;
	normal.y = hit_point.y - closest_point_on_axis.y;
	normal.z = hit_point.z - closest_point_on_axis.z;
	return (normalize(normal));
}
