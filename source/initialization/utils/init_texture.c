/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:19:42 by alisharu          #+#    #+#             */
/*   Updated: 2025/11/22 18:20:08 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_types.h"
#include "initialization.h"
#include <stdlib.h>
#include <string.h>

t_texture	*init_texture(char *path)
{
	t_texture	*texture;

	if (!path || strlen(path) == 0)
		return (NULL);
	texture = ft_calloc(1, sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->path = ft_strdup(path);
	if (!texture->path)
	{
		free(texture);
		return (NULL);
	}
	texture->img = NULL;
	texture->addr = NULL;
	texture->width = 0;
	texture->height = 0;
	return (texture);
}
