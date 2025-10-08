/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:44:36 by alisharu          #+#    #+#             */
/*   Updated: 2025/10/09 00:30:36 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "rendering.h"

double	intersect_cone_shadow(t_vector origin, t_vector dir, t_cone *cone)
{
	t_vector	oc;
	t_vector	v;
	t_quad		q;
	double		cos_angle;
	double		best_t;

	double t1, t2;
	double m1, m2;
	v = normalize(*(cone->axis));
	oc = vector_sub(origin, *(cone->apex));
	cos_angle = cos(cone->angle);
	q.a = pow(vector_dot(dir, v), 2.0) - cos_angle * cos_angle * vector_dot(dir,
			dir);
	q.b = 2.0 * (vector_dot(dir, v) * vector_dot(oc, v) - cos_angle * cos_angle
			* vector_dot(dir, oc));
	q.c = pow(vector_dot(oc, v), 2.0) - cos_angle * cos_angle * vector_dot(oc,
			oc);
	q.discriminant = q.b * q.b - 4.0 * q.a * q.c;
	if (q.discriminant < 0.0)
		return (-1.0);
	t1 = (-q.b - sqrt(q.discriminant)) / (2.0 * q.a);
	t2 = (-q.b + sqrt(q.discriminant)) / (2.0 * q.a);
	m1 = vector_dot(vector_addition(oc, vector_scale(dir, t1)), v);
	m2 = vector_dot(vector_addition(oc, vector_scale(dir, t2)), v);
	best_t = -1.0;
	if (t1 > 1e-6 && m1 >= 0.0 && m1 <= cone->height)
		best_t = t1;
	if (t2 > 1e-6 && m2 >= 0.0 && m2 <= cone->height && (best_t < 0
			|| t2 < best_t))
		best_t = t2;
	return (best_t);
}

double	intersect_cone(t_camera *cam, t_vector dir, t_cone *cone)
{
	t_vector	oc;
	t_vector	v;
	t_quad		q;
	double		cos_angle;
	double		best_t;

	double t1, t2;
	double m1, m2;
	v = normalize(*(cone->axis));
	oc = vector_sub(*(cam->position), *(cone->apex));
	cos_angle = cos(cone->angle);
	q.a = pow(vector_dot(dir, v), 2.0) - cos_angle * cos_angle * vector_dot(dir,
			dir);
	q.b = 2.0 * (vector_dot(dir, v) * vector_dot(oc, v) - cos_angle * cos_angle
			* vector_dot(dir, oc));
	q.c = pow(vector_dot(oc, v), 2.0) - cos_angle * cos_angle * vector_dot(oc,
			oc);
	q.discriminant = q.b * q.b - 4.0 * q.a * q.c;
	if (q.discriminant < 0.0)
		return (INFINITY);
	t1 = (-q.b - sqrt(q.discriminant)) / (2.0 * q.a);
	t2 = (-q.b + sqrt(q.discriminant)) / (2.0 * q.a);
	m1 = vector_dot(vector_addition(oc, vector_scale(dir, t1)), v);
	m2 = vector_dot(vector_addition(oc, vector_scale(dir, t2)), v);
	best_t = INFINITY;
	if (t1 > 1e-6 && m1 >= 0.0 && m1 <= cone->height)
		best_t = t1;
	if (t2 > 1e-6 && m2 >= 0.0 && m2 <= cone->height && t2 < best_t)
		best_t = t2;
	return (best_t);
}
t_vector	cone_normal(t_cone *cone, t_vector hit_point)
{
	t_vector	v;
	t_vector	co;
	double		k;
	double		cos_a;
	t_vector	n;

	v = normalize(*(cone->axis));
	co = vector_sub(hit_point, *(cone->apex));
	cos_a = cos(cone->angle);
	k = vector_dot(co, v);
	n = vector_sub(vector_scale(co, cos_a * cos_a), vector_scale(v, k * (1
					+ cos_a * cos_a)));
	n = normalize(n);
	if (vector_dot(n, v) > 0)
		n = vector_scale(n, -1);
	return (n);
}
