/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:32:12 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/01 09:28:47 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

static int	fill_sphere_vectors(t_sphere *sphere, char **pos, char **col)
{
	if (!pos || !col)
		return (0);
	sphere->position = ft_calloc(1, sizeof(t_vector));
	if (!sphere->position)
		return (0);
	sphere->color = ft_calloc(1, sizeof(t_color));
	if (!sphere->color)
		return (free(sphere->position), 0);
	sphere->position->x = ft_atof(pos[0]);
	sphere->position->y = ft_atof(pos[1]);
	sphere->position->z = ft_atof(pos[2]);
	sphere->color->red = ft_atoi(col[0]);
	sphere->color->green = ft_atoi(col[1]);
	sphere->color->blue = ft_atoi(col[2]);
	return (1);
}

t_sphere	*init_sphere(char **line)
{
	t_sphere	*sphere;
	char		**pos;
	char		**col;

	if (!line || !line[1] || !line[2] || !line[3])
		return (NULL);
	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	pos = ft_split(line[1], ',');
	col = ft_split(line[3], ',');
	if (!fill_sphere_vectors(sphere, pos, col))
		return (ft_free_matrix(pos), ft_free_matrix(col), free(sphere), NULL);
	sphere->diameter = ft_atof(line[2]);
	ft_free_matrix(pos);
	ft_free_matrix(col);
	return (sphere);
}
