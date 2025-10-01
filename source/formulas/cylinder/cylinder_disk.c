/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_disk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:43:10 by alisharu          #+#    #+#             */
/*   Updated: 2025/10/01 14:45:15 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"

static double	intersect_disk(t_camera *cam, t_vector ray, t_disk disk)
{
	double		denom;
	double		t;
	t_vector	p;

	denom = vector_dot(disk.normal, ray);
	if (fabs(denom) < 1e-6)
		return (INFINITY);
	t = vector_dot(vector_sub(disk.center, *(cam->position)), disk.normal)
		/ denom;
	if (t < 1e-6)
		return (INFINITY);
	p = vector_addition(*(cam->position), vector_scale(ray, t));
	if (vector_length(vector_sub(p, disk.center)) <= disk.radius)
		return (t);
	return (INFINITY);
}

double	check_disk_hit(t_camera *cam, t_vector ray, t_disk disk)
{
	return (intersect_disk(cam, ray, disk));
}
