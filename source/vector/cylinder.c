/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:44:24 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/16 18:20:58 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static double	solve_quadratic(double a, double b, double discriminant)
{
	double	sqrt_disc;
	double	t1;
	double	t2;

	sqrt_disc = sqrt(discriminant);
	t1 = (-b - sqrt_disc) / (2.0 * a);
	t2 = (-b + sqrt_disc) / (2.0 * a);
	return ((t1 > 0) ? t1 : (t2 > 0) ? t2 : INFINITY);
}

static double	compute_discriminant(t_vector oc, t_vector ray_dir,
		double radius)
{
	double	a;
	double	b;
	double	c;

	a = ray_dir.x * ray_dir.x + ray_dir.y * ray_dir.y;
	b = 2.0 * (oc.x * ray_dir.x + oc.y * ray_dir.y);
	c = oc.x * oc.x + oc.y * oc.y - radius * radius;
	return (b * b - 4.0 * a * c);
}

static int	is_within_height(double z, double height, double base_z)
{
	return (z >= base_z && z <= base_z + height);
}

double	intersect_cylinder(t_camera *camera, t_vector ray_dir,
		t_cylinder *cylinder)
{
	t_vector	oc;
	double		radius;
	double		discriminant;
	double		t;
	t_vector	intersection;

	oc = vector_sub(*(camera->position), *(cylinder->position));
	radius = cylinder->diameter / 2.0;
	discriminant = compute_discriminant(oc, ray_dir, radius);
	if (discriminant < 0)
		return (INFINITY);
	t = solve_quadratic(ray_dir.x * ray_dir.x + ray_dir.y * ray_dir.y, 2.0
			* (oc.x * ray_dir.x + oc.y * ray_dir.y), discriminant);
	if (t == INFINITY)
		return (INFINITY);
	intersection = vector_addition(*(camera->position), vector_scale(ray_dir,
				t));
	if (is_within_height(intersection.z, cylinder->height,
			cylinder->position->z))
		return (t);
	return (INFINITY);
}
