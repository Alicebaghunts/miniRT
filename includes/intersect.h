/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 23:09:14 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/24 21:40:51 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
#define INTERSECT_H

#include "object_types.h"
#include "vector.h"

double intersect_sphere(t_camera *cam, t_vector ray, t_sphere *sphere);
double intersect_plane(t_camera *cam, t_vector ray, t_plane *plane);
double intersect_disk(t_camera *cam, t_vector ray, t_vector center,
                      t_vector normal, double radius);
double	intersect_cylinder_shadow(t_vector origin, t_vector dir, t_cylinder *cy);
double intersect_plane_shadow(t_vector ray_origin, t_vector ray_dir, t_plane *plane);
double intersect_cylinder(t_camera *cam, t_vector dir, t_cylinder *cy);


#endif
