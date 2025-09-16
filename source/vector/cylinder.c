/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:44:24 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/16 16:03:11 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

double	intersect_cylinder(t_camera *camera, t_vector ray_dir,
		t_cylinder *cylinder)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		sqrt_disc;
	double		t1;
	double		t2;
	t_vector	intersection1;
	t_vector	intersection2;

	oc = vector_sub(*(camera->position), *(cylinder->position));
	a = ray_dir.x * ray_dir.x + ray_dir.y * ray_dir.y;
	b = 2.0 * (oc.x * ray_dir.x + oc.y * ray_dir.y);
	c = oc.x * oc.x + oc.y * oc.y - (cylinder->diameter / 2.0)
		* (cylinder->diameter / 2.0);
	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0)
		return (INFINITY);
	sqrt_disc = sqrt(discriminant);
	t1 = (-b - sqrt_disc) / (2.0 * a);
	t2 = (-b + sqrt_disc) / (2.0 * a);
	intersection1 = vector_addition(*(camera->position), vector_scale(ray_dir,
				t1));
	intersection2 = vector_addition(*(camera->position), vector_scale(ray_dir,
				t2));
	if (t1 > 0)
	{
		if (intersection1.z >= cylinder->position->z
			&& intersection1.z <= cylinder->position->z + cylinder->height)
			return (t1);
	}
	if (t2 > 0)
	{
		if (intersection2.z >= cylinder->position->z
			&& intersection2.z <= cylinder->position->z + cylinder->height)
			return (t2);
	}
	return (INFINITY);
}
