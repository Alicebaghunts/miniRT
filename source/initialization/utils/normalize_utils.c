/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:57:27 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/27 17:30:10 by alisharu         ###   ########.fr       */
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
		return (normal.z = -cyl->direction->z, normal);
	}
	closest_point_on_axis.x = cyl->position->x + cyl->direction->x * projection;
	closest_point_on_axis.y = cyl->position->y + cyl->direction->y * projection;
	closest_point_on_axis.z = cyl->position->z + cyl->direction->z * projection;
	normal.x = hit_point.x - closest_point_on_axis.x;
	normal.y = hit_point.y - closest_point_on_axis.y;
	normal.z = hit_point.z - closest_point_on_axis.z;
	return (normalize(normal));
}
