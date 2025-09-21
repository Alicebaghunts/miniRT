/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:44:24 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/21 23:11:20 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"
#include "intersect.h"
#include <math.h>
#include <float.h>


double intersect_cylinder_side(t_camera *cam, t_vector ray, t_cylinder *cy)
{
    t_vector oc = vector_sub(*(cam->position), *(cy->position));
    t_vector dir = *(cy->direction);
    double radius = cy->diameter / 2.0;

    double a = vector_dot(ray, ray) - pow(vector_dot(ray, dir), 2);
    double b = 2 * (vector_dot(ray, oc) - vector_dot(ray, dir) * vector_dot(oc, dir));
    double c = vector_dot(oc, oc) - pow(vector_dot(oc, dir), 2) - radius * radius;

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return INFINITY;

    double sqrt_disc = sqrt(discriminant);
    double t1 = (-b - sqrt_disc) / (2 * a);
    double t2 = (-b + sqrt_disc) / (2 * a);

    double t = INFINITY;
    if (t1 > 1e-6) t = t1;
    if (t2 > 1e-6 && t2 < t) t = t2;

    if (t == INFINITY)
        return INFINITY;

    t_vector p = vector_addition(*(cam->position), vector_scale(ray, t));
    double proj = vector_dot(vector_sub(p, *(cy->position)), dir);
    if (proj < 0 || proj > cy->height)
        return INFINITY;

    return t;
}

double intersect_cylinder(t_camera *cam, t_vector ray, t_cylinder *cy)
{
    double t_side = intersect_cylinder_side(cam, ray, cy);

    t_vector top_center = vector_addition(*(cy->position), vector_scale(*(cy->direction), cy->height));
    t_vector bottom_center = *(cy->position);
    double radius = cy->diameter / 2.0;

    double t_cap_top = intersect_disk(cam, ray, top_center, *(cy->direction), radius);
    double t_cap_bottom = intersect_disk(cam, ray, bottom_center,
                                         vector_scale(*(cy->direction), -1.0), radius);

    double t_min = INFINITY;
    if (t_side > 0.0 && t_side < t_min) t_min = t_side;
    if (t_cap_top > 0.0 && t_cap_top < t_min) t_min = t_cap_top;
    if (t_cap_bottom > 0.0 && t_cap_bottom < t_min) t_min = t_cap_bottom;

    return t_min;
}
