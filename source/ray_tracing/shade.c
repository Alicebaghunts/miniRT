/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:50:25 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/27 19:10:48 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "rendering.h"

static void	init_light_info_base(t_light_info *li, t_shade_info *si,
		t_light *light)
{
	li->result = si->result;
	li->obj_color = si->obj_color;
	li->light = light;
	li->normal = si->normal;
}

static void	compute_lights(t_shade_info info)
{
	t_list			*l_node;
	t_light			*light;
	t_shadow_info	shadow;
	t_light_info	light_info;

	l_node = info.scene->lights;
	while (l_node)
	{
		light = (t_light *)l_node->content;
		shadow.scene = info.scene;
		shadow.hit_point = info.hit_point;
		shadow.normal = info.normal;
		shadow.light_dir = vector_sub(*(light->position), info.hit_point);
		shadow.light_dist = vector_length(shadow.light_dir);
		shadow.ignore = info.obj;
		if (!in_shadow(shadow))
		{
			init_light_info_base(&light_info, &info, light);
			light_info.view_dir = info.view_dir;
			light_info.hit_point = info.hit_point;
			add_light_contribution_struct(&light_info);
		}
		l_node = l_node->next;
	}
}

t_color	shade(t_scene *scene, t_vector hit_point, t_vector normal,
		t_object *obj)
{
	t_color			result;
	t_color			obj_color;
	t_camera		*cam;
	t_vector		view_dir;
	t_shade_info	info;

	obj_color = get_object_color(obj);
	cam = (t_camera *)scene->camera->content;
	view_dir = normalize(vector_sub(*(cam->position), hit_point));
	result = compute_ambient(scene, obj_color);
	info.scene = scene;
	info.hit_point = hit_point;
	info.normal = normal;
	info.view_dir = view_dir;
	info.obj = obj;
	info.obj_color = obj_color;
	info.result = &result;
	compute_lights(info);
	if (result.red > 255)
		result.red = 255;
	if (result.green > 255)
		result.green = 255;
	if (result.blue > 255)
		result.blue = 255;
	return (result);
}
