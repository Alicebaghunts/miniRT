/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:50:25 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/16 15:38:12 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static int	in_shadow(t_scene *scene, t_vector hit_point, t_vector light_dir,
		double light_dist)
{
	t_list		*node;
	t_object	*obj;
	double		t;

	node = scene->objects;
	while (node)
	{
		obj = (t_object *)node->content;
		if (obj->type == 's')
		{
			t = intersect_sphere_shadow(hit_point, light_dir,
					obj->data->sphere);
			if (t > 1e-6 && t < light_dist)
				return (1); // в тени
		}
		else if (obj->type == 'p')
		{
			t = intersect_plane_shadow(hit_point, light_dir, obj->data->plane);
			if (t > 1e-6 && t < light_dist)
				return (1);
		}
		// TODO: cylinder shadows
		node = node->next;
	}
	return (0); // света ничто не перекрыло
}

t_color	shade(t_scene *scene, t_vector hit_point, t_vector normal,
		t_object *obj)
{
	t_color		result;
	t_list		*l_node;
	t_light		*light;
	t_vector	light_dir;
	double		light_dist;
	double		diff;
	t_color		obj_color;

	if (obj->type == 's')
		obj_color = *(obj->data->sphere->color);
	else if (obj->type == 'p')
		obj_color = *(obj->data->plane->color);
	else
		obj_color = *(obj->data->cylinder->color);
	result.red = (int)(obj_color.red * scene->ambient->color->red / 255.0
			* scene->ambient->light_ratio);
	result.green = (int)(obj_color.green * scene->ambient->color->green / 255.0
			* scene->ambient->light_ratio);
	result.blue = (int)(obj_color.blue * scene->ambient->color->blue / 255.0
			* scene->ambient->light_ratio);
	l_node = scene->lights;
	while (l_node)
	{
		light = (t_light *)l_node->content;
		light_dir = vector_sub(*(light->position), hit_point);
		light_dist = vector_length(light_dir);
		light_dir = normalize(light_dir);
		if (!in_shadow(scene, hit_point, light_dir, light_dist))
		{
			diff = fmax(0.0, vector_dot(normal, light_dir));
			result.red += (int)(obj_color.red * light->color->red / 255.0
					* light->brightness_ratio * diff);
			result.green += (int)(obj_color.green * light->color->green / 255.0
					* light->brightness_ratio * diff);
			result.blue += (int)(obj_color.blue * light->color->blue / 255.0
					* light->brightness_ratio * diff);
		}
		l_node = l_node->next;
	}
	if (result.red > 255)
		result.red = 255;
	if (result.green > 255)
		result.green = 255;
	if (result.blue > 255)
		result.blue = 255;
	return (result);
}
