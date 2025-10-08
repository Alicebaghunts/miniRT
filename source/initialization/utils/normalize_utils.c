/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:57:27 by alisharu          #+#    #+#             */
/*   Updated: 2025/10/08 19:14:00 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

double	vector_length(t_vector vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y + vector.z
			* vector.z));
}

t_vector	cylinder_normal(t_cylinder *cyl, t_vector hit_point)
{
	t_vector	rel_to_center;
	double		proj_on_axis;
	t_vector	axis;
	t_vector	side;

	axis = normalize(*(cyl->direction));
	rel_to_center.x = hit_point.x - cyl->position->x;
	rel_to_center.y = hit_point.y - cyl->position->y;
	rel_to_center.z = hit_point.z - cyl->position->z;
	proj_on_axis = rel_to_center.x * axis.x + rel_to_center.y * axis.y
		+ rel_to_center.z * axis.z;
	if (proj_on_axis >= (cyl->height / 2.0) - 1e-6)
		return (axis);
	if (proj_on_axis <= -(cyl->height / 2.0) + 1e-6)
		return (vector_scale(axis, -1));
	side = vector_sub(rel_to_center, vector_scale(axis, proj_on_axis));
	return (normalize(side));
}
