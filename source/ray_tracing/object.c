/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:19:13 by alisharu          #+#    #+#             */
/*   Updated: 2025/10/08 14:38:53 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

t_color	get_object_color(t_object *obj)
{
	if (!obj || !obj->data)
		return ((t_color){0, 0, 0});
	if (obj->type == 's' && obj->data->sphere)
		return (*(obj->data->sphere->color));
	else if (obj->type == 'p' && obj->data->plane)
		return (*(obj->data->plane->color));
	else if (obj->type == 'c' && obj->data->cylinder)
		return (*(obj->data->cylinder->color));
	else if (obj->type == 'o' && obj->data->cone)
		return (*(obj->data->cone->color));
	return ((t_color){0, 0, 0});
}
