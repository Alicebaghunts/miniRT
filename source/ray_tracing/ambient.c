/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:16:05 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/27 19:14:08 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

t_color	compute_ambient(t_scene *scene, t_color obj_color)
{
	t_color	result;

	result.red = (int)(obj_color.red * scene->ambient->color->red / 255.0
			* scene->ambient->light_ratio);
	result.green = (int)(obj_color.green * scene->ambient->color->green / 255.0
			* scene->ambient->light_ratio);
	result.blue = (int)(obj_color.blue * scene->ambient->color->blue / 255.0
			* scene->ambient->light_ratio);
	return (result);
}
