/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:44:24 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/24 21:39:01 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "rendering.h"
#include <float.h>
#include <math.h>

double	intersect_cylinder_side(t_camera *cam, t_vector ray, t_cylinder *cy)
{
	t_vector	oc;
	t_vector	dir;
	double		radius;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		sqrt_disc;
	double		t1;
	double		t2;
	double		t;
	t_vector	p;
	double		proj;

	oc = vector_sub(*(cam->position), *(cy->position));
	dir = *(cy->direction);
	radius = cy->diameter / 2.0;
	a = vector_dot(ray, ray) - pow(vector_dot(ray, dir), 2);
	b = 2 * (vector_dot(ray, oc) - vector_dot(ray, dir) * vector_dot(oc, dir));
	c = vector_dot(oc, oc) - pow(vector_dot(oc, dir), 2) - radius * radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (INFINITY);
	sqrt_disc = sqrt(discriminant);
	t1 = (-b - sqrt_disc) / (2 * a);
	t2 = (-b + sqrt_disc) / (2 * a);
	t = INFINITY;
	if (t1 > 1e-6)
		t = t1;
	if (t2 > 1e-6 && t2 < t)
		t = t2;
	if (t == INFINITY)
		return (INFINITY);
	p = vector_addition(*(cam->position), vector_scale(ray, t));
	proj = vector_dot(vector_sub(p, *(cy->position)), dir);
	if (proj < 0 || proj > cy->height)
		return (INFINITY);
	return (t);
}

double	intersect_cylinder_shadow(t_vector origin, t_vector dir, t_cylinder *cy)
{
	t_vector	oc;
	t_vector	axis;
	double		radius;
	t_vector	d_proj;
	t_vector	oc_proj;
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t1;
	double		t2;
	double		t;
	t_vector	hit;
	double		dist;

	oc = vector_sub(origin, *(cy->position));
	axis = normalize(*(cy->direction));
	radius = cy->diameter / 2.0;
	d_proj = vector_sub(dir, vector_scale(axis, vector_dot(dir, axis)));
	oc_proj = vector_sub(oc, vector_scale(axis, vector_dot(oc, axis)));
	a = vector_dot(d_proj, d_proj);
	b = 2.0 * vector_dot(oc_proj, d_proj);
	c = vector_dot(oc_proj, oc_proj) - radius * radius;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (-1.0);
	t1 = (-b - sqrt(disc)) / (2 * a);
	t2 = (-b + sqrt(disc)) / (2 * a);
	if (t1 > 1e-6)
		t = t1;
	else
		t = t2;
	if (t < 1e-6)
		return (-1.0);
	hit = vector_addition(origin, vector_scale(dir, t));
	dist = vector_dot(vector_sub(hit, *(cy->position)), axis);
	if (dist < 0 || dist > cy->height)
		return (-1.0);
	return (t);
}


double	intersect_cylinder(t_camera *cam, t_vector dir, t_cylinder *cy)
{
	t_vector	oc;
	t_vector	axis;
	double		radius;
	t_vector	d_proj;
	t_vector	oc_proj;
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t1;
	double		t2;
	double		t;
	t_vector	hit;
	double		dist;

	oc = vector_sub(*(cam->position), *(cy->position));
	axis = normalize(*(cy->direction));
	radius = cy->diameter / 2.0;
	d_proj = vector_sub(dir, vector_scale(axis, vector_dot(dir, axis)));
	oc_proj = vector_sub(oc, vector_scale(axis, vector_dot(oc, axis)));
	a = vector_dot(d_proj, d_proj);
	b = 2.0 * vector_dot(oc_proj, d_proj);
	c = vector_dot(oc_proj, oc_proj) - radius * radius;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (-1.0);
	t1 = (-b - sqrt(disc)) / (2 * a);
	t2 = (-b + sqrt(disc)) / (2 * a);
	if (t1 > 1e-6)
		t = t1;
	else
		t = t2;
	if (t < 1e-6)
		return (-1.0);
	hit = vector_addition(*(cam->position), vector_scale(dir, t));
	dist = vector_dot(vector_sub(hit, *(cy->position)), axis);
	if (dist < 0 || dist > cy->height)
		return (-1.0);
	return (t);
}
