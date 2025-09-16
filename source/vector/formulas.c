/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:13:20 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/16 16:03:03 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

t_vector	compute_ray(t_camera *cam, double px, double py)
{
	double		aspect;
	double		scale;
	double		sx;
	double		sy;
	t_vector	right;
	t_vector	up;
	t_vector	dir;
	t_vector	world_up;

	aspect = (double)MLX_X / (double)MLX_Y;
	scale = tan(cam->field_of_view * M_PI / 180.0 / 2.0);
	sx = (2.0 * (px + 0.5) / MLX_X - 1.0) * aspect * scale;
	sy = (1.0 - 2.0 * (py + 0.5) / MLX_Y) * scale;
	world_up = (t_vector){0, 1, 0};
	if (fabs(cam->direction->x) < 1e-6 && fabs(cam->direction->z) < 1e-6)
		world_up = (t_vector){0, 0, 1};
	right = normalize(vector_cross(world_up, *(cam->direction)));
	up = normalize(vector_cross(*(cam->direction), right));
	dir = vector_addition(vector_addition(*(cam->direction), vector_scale(right,
					sx)), vector_scale(up, sy));
	return (normalize(dir));
}

double	intersect_sphere(t_camera *camera, t_vector ray_dir, t_sphere *sphere)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t1;
	double		t2;
	double		radius;

	radius = sphere->diameter / 2.0;
	oc = vector_sub(*camera->position, *(sphere->position));
	a = vector_dot(ray_dir, ray_dir);
	b = 2.0 * vector_dot(ray_dir, oc);
	c = vector_dot(oc, oc) - radius * radius;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (INFINITY);
	t1 = (-b - sqrt(disc)) / (2.0 * a);
	t2 = (-b + sqrt(disc)) / (2.0 * a);
	if (t1 > 0 && t1 < t2)
		return (t1);
	else if (t2 > 0)
		return (t2);
	return (INFINITY);
}
