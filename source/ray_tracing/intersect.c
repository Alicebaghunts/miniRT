/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:09:28 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/16 01:30:05 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

double intersect_sphere_shadow(t_vector origin, t_vector dir, t_sphere *sphere)
{
	t_vector oc = vector_sub(origin, *(sphere->position));
	double radius = sphere->diameter / 2.0;
	double a = vector_dot(dir, dir);
	double b = 2.0 * vector_dot(oc, dir);
	double c = vector_dot(oc, oc) - radius * radius;
	double discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return -1.0;
	double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
	double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
	if (t1 > 1e-6)
		return t1;
	if (t2 > 1e-6)
		return t2;
	return -1.0;
}

double intersect_plane_shadow(t_vector origin, t_vector dir, t_plane *plane)
{
	double denom = vector_dot(*(plane->normal), dir);
	if (fabs(denom) < 1e-6)
		return -1.0;
	double t = vector_dot(vector_sub(*(plane->position), origin), *(plane->normal)) / denom;
	if (t > 1e-6)
		return t;
	return -1.0;
}
