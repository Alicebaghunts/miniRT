/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:09:28 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/21 23:09:57 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

double	intersect_sphere_shadow(t_vector origin, t_vector dir, t_sphere *sphere)
{
	t_vector	oc;
	double		radius;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		t1;
	double		t2;

	oc = vector_sub(origin, *(sphere->position));
	radius = sphere->diameter / 2.0;
	a = vector_dot(dir, dir);
	b = 2.0 * vector_dot(oc, dir);
	c = vector_dot(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	t1 = (-b - sqrt(discriminant)) / (2.0 * a);
	t2 = (-b + sqrt(discriminant)) / (2.0 * a);
	if (t1 > 1e-10)
		return (t1);
	if (t2 > 1e-10)
		return (t2);
	return (-1.0);
}

double	intersect_plane_shadow(t_vector origin, t_vector dir, t_plane *plane)
{
	double	denom;
	double	t;

	denom = vector_dot(*(plane->normal), dir);
	if (fabs(denom) < 1e-6)
		return (-1.0);
	t = vector_dot(vector_sub(*(plane->position), origin), *(plane->normal))
		/ denom;
	if (t > 1e-6)
		return (t);
	return (-1.0);
}

