/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:23:03 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/01 16:01:33 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

void normalize_vectors(t_scene *scene)
{
    t_list      *node;
    t_object    *objects;

    if (!scene)
        return ;
    node = scene->camera;
    while (node)
    {
        if (node->content && ((t_camera *)node->content)->direction)
            *((t_camera *)node->content)->direction = 
                normalize(*((t_camera *)node->content)->direction);
        node = node->next;
    }
    node = scene->objects;
    while (node)
    {
        objects = (t_object *)node->content;
        if (objects)
        {
            if (objects->type == 'p' && objects->data->plane && objects->data->plane->normal)
                *objects->data->plane->normal = normalize(*objects->data->plane->normal);
            else if (objects->type == 'c' && objects->data->cylinder &&
                objects->data->cylinder->direction)
                *objects->data->cylinder->direction = normalize(
                    *objects->data->cylinder->direction);
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
