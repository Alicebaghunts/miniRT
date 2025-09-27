/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:23:03 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/25 19:07:20 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

double	vector_length(t_vector vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y + vector.z
			* vector.z));
}

static void	normalize_camera_direction(t_camera *camera)
{
	if (camera && camera->direction)
		*camera->direction = normalize(*camera->direction);
}

static void	normalize_object_direction(t_object *object)
{
	if (object)
	{
		if (object->type == 'p' && object->data->plane
			&& object->data->plane->normal)
			*object->data->plane->normal
				= normalize(*object->data->plane->normal);
		else if (object->type == 'c' && object->data->cylinder
			&& object->data->cylinder->direction)
			*object->data->cylinder->direction
				= normalize(*object->data->cylinder->direction);
	}
}

void	normalize_vectors(t_scene *scene)
{
	t_list		*node;
	t_camera	*camera;
	t_object	*object;

	if (!scene)
		return ;
	node = scene->camera;
	while (node)
	{
		camera = (t_camera *)node->content;
		normalize_camera_direction(camera);
		node = node->next;
	}
	node = scene->objects;
	while (node)
	{
		object = (t_object *)node->content;
		normalize_object_direction(object);
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
	if (projection >= cyl->height - 1e-6)
		return (*(cyl->direction));
	if (projection <= 1e-6)
	{
		normal.x = -cyl->direction->x;
		normal.y = -cyl->direction->y;
		normal.z = -cyl->direction->z;
		return (normal);
	}
	closest_point_on_axis.x = cyl->position->x + cyl->direction->x * projection;
	closest_point_on_axis.y = cyl->position->y + cyl->direction->y * projection;
	closest_point_on_axis.z = cyl->position->z + cyl->direction->z * projection;
	normal.x = hit_point.x - closest_point_on_axis.x;
	normal.y = hit_point.y - closest_point_on_axis.y;
	normal.z = hit_point.z - closest_point_on_axis.z;
	return (normalize(normal));
}
