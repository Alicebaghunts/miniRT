/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:19:13 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/27 18:24:41 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

t_color	get_object_color(t_object *obj)
{
	if (obj->type == 's')
		return (*(obj->data->sphere->color));
	else if (obj->type == 'p')
		return (*(obj->data->plane->color));
	else
		return (*(obj->data->cylinder->color));
}
