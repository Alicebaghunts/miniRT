/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:45:17 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/17 14:50:52 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

double intersect_plane(t_camera *camera, t_vector ray_dir, t_plane *plane)
{
    double t;
    t_vector oc = vector_sub(*(camera->position), *(plane->position));
    double denom = vector_dot(ray_dir, *(plane->normal));
    if (fabs(denom) < 1e-6)
        return (INFINITY);
    t = -vector_dot(oc, *(plane->normal)) / denom;
    if (t > 0)
        return (t);
    return (INFINITY);
}
