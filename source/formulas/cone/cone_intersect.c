/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:44:36 by alisharu          #+#    #+#             */
/*   Updated: 2025/10/08 19:39:49 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "rendering.h"

double	intersect_cone_shadow(t_vector origin, t_vector dir, t_cone *cone)
{
	t_vector	oc;
	t_vector	v;
	t_quad		q;
	double		c2;
	double		t1;
	double		t2;
	double		m1;
	double		m2;

	v = normalize(*(cone->axis));
	oc = vector_sub(origin, *(cone->apex));
	// Use implicit cone: (p·v)^2 - cos^2(theta) |p|^2 = 0
	c2 = cos(cone->angle);
	c2 = c2 * c2;
	q.a = pow(vector_dot(dir, v), 2.0) - c2 * vector_dot(dir, dir);
	q.b = 2.0 * (vector_dot(dir, v) * vector_dot(oc, v) - c2 * vector_dot(dir,
				oc));
	q.c = pow(vector_dot(oc, v), 2.0) - c2 * vector_dot(oc, oc);
	q.discriminant = q.b * q.b - 4.0 * q.a * q.c;
	if (q.discriminant < 0.0)
		return (-1.0);
	t1 = (-q.b - sqrt(q.discriminant)) / (2.0 * q.a);
	t2 = (-q.b + sqrt(q.discriminant)) / (2.0 * q.a);
	m1 = -vector_dot(vector_addition(oc, vector_scale(dir, t1)), v);
	m2 = -vector_dot(vector_addition(oc, vector_scale(dir, t2)), v);
	if (t1 > 1e-6 && (m1 >= 0.0 && m1 <= cone->height))
		return (t1);
	if (t2 > 1e-6 && m2 >= 0.0 && m2 <= cone->height)
		return (t2);
	return (-1.0);
}

double	intersect_cone(t_camera *cam, t_vector dir, t_cone *cone)
{
	t_vector	oc;
	t_vector	v;
	t_quad		q;
	double		c2;

	double t1, t2;
	double m1, m2;
	v = normalize(*(cone->axis));
	oc = vector_sub(*(cam->position), *(cone->apex));
	c2 = cos(cone->angle);
	c2 = c2 * c2;
	q.a = pow(vector_dot(dir, v), 2.0) - c2 * vector_dot(dir, dir);
	q.b = 2.0 * (vector_dot(dir, v) * vector_dot(oc, v) - c2 * vector_dot(dir,
				oc));
	q.c = pow(vector_dot(oc, v), 2.0) - c2 * vector_dot(oc, oc);
	q.discriminant = q.b * q.b - 4.0 * q.a * q.c;
	if (q.discriminant < 0.0)
		return (INFINITY);
	t1 = (-q.b - sqrt(q.discriminant)) / (2.0 * q.a);
	t2 = (-q.b + sqrt(q.discriminant)) / (2.0 * q.a);
	m1 = vector_dot(vector_addition(oc, vector_scale(dir, t1)), v);
	m2 = vector_dot(vector_addition(oc, vector_scale(dir, t2)), v);
	if (t1 > 1e-6 && (m1 >= 0.0 && m1 <= cone->height))
		return (t1);
	if (t2 > 1e-6 && (m2 >= 0.0 && m2 <= cone->height))
		return (t2);
	return (INFINITY);
}

t_vector	cone_normal(t_cone *cone, t_vector hit_point)
{
	t_vector	v;
	t_vector	co;
	double		c2;
	t_vector	n;

	v = normalize(*(cone->axis));
	co = vector_sub(hit_point, *(cone->apex));
	c2 = cos(cone->angle);
	c2 = c2 * c2;
	// Gradient of f(p) = (p·v)^2 - c2 * |p|^2 is 2[(p·v)v - c2 p]
	n = vector_sub(vector_scale(v, vector_dot(co, v)), vector_scale(co, c2));
	n = vector_sub(vector_scale(co, c2), vector_scale(v, vector_dot(co, v)));
    return (normalize(n));
}
