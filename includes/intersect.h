/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 23:09:14 by alisharu          #+#    #+#             */
/*   Updated: 2025/10/01 14:56:04 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "object_types.h"
# include "rendering.h"
# include "vector.h"

typedef struct s_ray_data
{
	t_camera	*cam;
	t_vector	ray;
	t_cylinder	*cy;
}				t_ray_data;

typedef struct s_disk
{
	t_vector	center;
	t_vector	normal;
	double		radius;
}				t_disk;

typedef struct s_quad
{
	double		a;
	double		b;
	double		c;
	double		discriminant;
}				t_quad;

double			intersect_sphere(t_camera *cam, t_vector ray, t_sphere *sphere);
double			intersect_plane(t_camera *cam, t_vector ray, t_plane *plane);
double			intersect_cylinder_shadow(t_vector origin, t_vector dir,
					t_cylinder *cy);
double			intersect_plane_shadow(t_vector ray_origin, t_vector ray_dir,
					t_plane *plane);
double			intersect_cylinder_side(t_ray_data data, t_hit_type *hit_type);
double			intersect_cylinder_caps(t_ray_data data, t_hit_type *hit_type);
double			intersect_cylinder(t_ray_data data, t_hit_type *hit_type);
int				check_cylinder_height(t_vector hit, t_cylinder *cy,
					t_vector axis);
double			check_disk_hit(t_camera *cam, t_vector ray, t_disk disk);
t_quad			cylinder_coeffs(t_vector dir, t_vector oc, t_vector axis,
					double radius);
double			pick_root(t_quad q);
t_vector		compute_hit(t_camera *cam, t_vector dir, double t);
#endif
