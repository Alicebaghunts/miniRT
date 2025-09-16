/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:50:25 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/16 21:15:43 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

double	intersect_cylinder_shadow(t_vector origin, t_vector dir,
		t_cylinder *cylinder)
{
	t_vector	oc;
	double		radius;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		t1;
	double		t2;

	oc = vector_sub(origin, *(cylinder->position));
	radius = cylinder->diameter / 2.0;
	a = dir.x * dir.x + dir.y * dir.y;
	b = 2.0 * (oc.x * dir.x + oc.y * dir.y);
	c = oc.x * oc.x + oc.y * oc.y - radius * radius;
	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0)
		return (-1.0);
	t1 = (-b - sqrt(discriminant)) / (2.0 * a);
	t2 = (-b + sqrt(discriminant)) / (2.0 * a);
	if (t1 > 1e-6)
		return (t1);
	if (t2 > 1e-6)
		return (t2);
	return (-1.0);
}

static int	in_shadow(t_scene *scene, t_vector hit_point, t_vector light_dir,
		double light_dist)
{
	t_list		*node;
	t_object	*obj;
	double		t;

	light_dir = normalize(light_dir);
	node = scene->objects;
	while (node)
	{
		obj = (t_object *)node->content;
		if (obj->type == 's')
		{
			t = intersect_sphere_shadow(hit_point, light_dir,
					obj->data->sphere);
			if (t > 1e-6 && t < light_dist)
				return (1);
		}
		else if (obj->type == 'p')
		{
			t = intersect_plane_shadow(hit_point, light_dir, obj->data->plane);
			if (t > 1e-6 && t < light_dist)
				return (1);
		}
		else if (obj->type == 'c')
		{
			t = intersect_cylinder_shadow(hit_point, light_dir,
					obj->data->cylinder);
			if (t > 1e-6 && t < light_dist)
				return (1);
		}
		node = node->next;
	}
	return (0);
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
