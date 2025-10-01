/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligthing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:55:14 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/27 19:19:35 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "rendering.h"

static void	add_diffuse(t_light_info *info)
{
	t_vector	light_dir;
	double		diff;

	light_dir = normalize(vector_sub(*(info->light->position),
				info->hit_point));
	diff = fmax(0.0, vector_dot(info->normal, light_dir));
	if (diff > 0.0)
	{
		info->result->red += (int)(info->obj_color.red * info->light->color->red
				/ 255.0 * info->light->brightness_ratio * diff);
		info->result->green += (int)(info->obj_color.green
				* info->light->color->green / 255.0
				* info->light->brightness_ratio * diff);
		info->result->blue += (int)(info->obj_color.blue
				* info->light->color->blue / 255.0
				* info->light->brightness_ratio * diff);
	}
}

static void	add_specular(t_light_info *info)
{
	t_vector		light_dir;
	t_vector		reflect_dir;
	double			spec;
	const double	ks = 1.0;

	light_dir = normalize(vector_sub(*(info->light->position),
				info->hit_point));
	reflect_dir = normalize(vector_sub(vector_scale(info->normal, 2.0
					* vector_dot(info->normal, light_dir)), light_dir));
	spec = pow(fmax(0.0, vector_dot(info->view_dir, reflect_dir)), 64);
	if (spec > 0.0)
	{
		info->result->red += (int)(info->light->color->red * ks
				* info->light->brightness_ratio * spec);
		info->result->green += (int)(info->light->color->green * ks
				* info->light->brightness_ratio * spec);
		info->result->blue += (int)(info->light->color->blue * ks
				* info->light->brightness_ratio * spec);
	}
}

void	add_light_contribution_struct(t_light_info *info)
{
	add_diffuse(info);
	add_specular(info);
}
