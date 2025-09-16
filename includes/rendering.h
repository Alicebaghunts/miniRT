/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:12:05 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/16 18:37:56 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "initialization.h"

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	t_scene		*scene;
}				t_mlx;

typedef struct s_hit
{
	double		min_t;
	t_object	*closest;
	t_vector	hit_point;
	t_vector	normal;
	t_color		shaded;
}				t_hit;

void			drawing(t_mlx *app);
double			vector_length(t_vector vector);
double			vector_dot(t_vector a, t_vector b);
t_vector		vector_sub(t_vector a, t_vector b);
t_vector		vector_cross(t_vector a, t_vector b);
t_vector		vector_scale(t_vector v, double s);
t_vector		vector_addition(t_vector a, t_vector b);
double			intersect_sphere(t_camera *camera, t_vector ray_dir,
					t_sphere *sphere);
t_vector		compute_ray(t_camera *cam, double u, double v);
double			intersect_plane(t_camera *camera, t_vector ray_dir,
					t_plane *plane);
double			intersect_cylinder(t_camera *camera, t_vector ray_dir,
					t_cylinder *cylinder);
t_color			shade(t_scene *scene, t_vector hit_point, t_vector normal,
					t_object *obj);

double			intersect_sphere_shadow(t_vector ray_origin, t_vector ray_dir,
					t_sphere *sphere);

double			intersect_plane_shadow(t_vector ray_origin, t_vector ray_dir,
					t_plane *plane);
#endif
