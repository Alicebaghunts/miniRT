/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:05:15 by alisharu          #+#    #+#             */
/*   Updated: 2025/10/01 14:44:34 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#define EPSILON 1e-6

t_vector	get_cylinder_normal(t_cylinder *cy, t_vector hit)
{
	t_vector	axis;
	t_vector	top_center;
	t_vector	bottom_center;
	t_vector	hit_dir;

	axis = normalize(*(cy->direction));
	top_center = vector_addition(*(cy->position), vector_scale(axis, cy->height
				/ 2.0));
	bottom_center = vector_sub(*(cy->position), vector_scale(axis, cy->height
				/ 2.0));
	if (fabs(vector_length(vector_sub(hit, top_center))) <= cy->diameter / 2.0
		+ 1e-6)
		return (axis);
	if (fabs(vector_length(vector_sub(hit, bottom_center))) <= cy->diameter
		/ 2.0 + 1e-6)
		return (vector_scale(axis, -1));
	hit_dir = vector_sub(hit, *(cy->position));
	return (normalize(vector_sub(hit_dir, vector_scale(axis, vector_dot(hit_dir,
						axis)))));
}

int	check_cylinder_height(t_vector hit, t_cylinder *cy, t_vector axis)
{
	t_vector	base_to_hit;
	double		dist;

	base_to_hit = vector_sub(hit, *(cy->position));
	dist = vector_dot(base_to_hit, axis);
	return (dist >= -EPSILON && dist <= cy->height + EPSILON);
}

static t_vector	get_cyl_center(t_cylinder *cy, t_vector axis, int top)
{
	if (top)
		return (vector_addition(*(cy->position), vector_scale(axis, cy->height
					/ 2.0)));
	return (vector_sub(*(cy->position), vector_scale(axis, cy->height / 2.0)));
}

double	intersect_cylinder_caps(t_ray_data data, t_hit_type *hit_type)
{
	t_vector	axis;
	t_disk		top_disk;
	t_disk		bottom_disk;
	double		t_top;
	double		t_bottom;

	axis = normalize(*(data.cy->direction));
	top_disk.center = get_cyl_center(data.cy, axis, 1);
	top_disk.normal = axis;
	top_disk.radius = data.cy->diameter / 2.0;
	bottom_disk.center = get_cyl_center(data.cy, axis, 0);
	bottom_disk.normal = vector_scale(axis, -1);
	bottom_disk.radius = data.cy->diameter / 2.0;
	t_top = check_disk_hit(data.cam, data.ray, top_disk);
	t_bottom = check_disk_hit(data.cam, data.ray, bottom_disk);
	if (t_top == INFINITY && t_bottom == INFINITY)
		return (INFINITY);
	if (t_top == INFINITY || (t_bottom != INFINITY && t_bottom < t_top))
	{
		*hit_type = HIT_CYLINDER_BOTTOM;
		return (t_bottom);
	}
	*hit_type = HIT_CYLINDER_TOP;
	return (t_top);
}
