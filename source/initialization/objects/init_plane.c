/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:34:49 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/01 00:34:50 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

static int	fill_plane_vectors(t_plane *plane, char **pos, char **norm,
		char **col)
{
	if (!pos || !norm || !col)
		return (0);
	plane->position = ft_calloc(1, sizeof(t_vector));
    if (!plane->position)
        return (0);
	plane->normal = ft_calloc(1, sizeof(t_vector));
    if (!plane->normal)
		return (free(plane->position), 0);
	plane->color = ft_calloc(1, sizeof(t_color));
	if (!plane->color)
		return (free(plane->position), free(plane->normal), 0);
	plane->position->x = ft_atof(pos[0]);
	plane->position->y = ft_atof(pos[1]);
	plane->position->z = ft_atof(pos[2]);
	plane->normal->x = ft_atof(norm[0]);
	plane->normal->y = ft_atof(norm[1]);
	plane->normal->z = ft_atof(norm[2]);
	plane->color->red = ft_atoi(col[0]);
	plane->color->green = ft_atoi(col[1]);
	plane->color->blue = ft_atoi(col[2]);
	return (1);
}

t_plane	*init_plane(char **line)
{
	t_plane	*plane;
	char	**pos;
	char	**norm;
	char	**col;

	if (!line || !line[1] || !line[2] || !line[3])
		return (NULL);
	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
		return (NULL);
	pos = ft_split(line[1], ',');
	norm = ft_split(line[2], ',');
	col = ft_split(line[5], ',');
	if (!fill_plane_vectors(plane, pos, norm, col))
		return (ft_free_matrix(pos), ft_free_matrix(norm), ft_free_matrix(col),
			free(plane), NULL);
	ft_free_matrix(pos);
	ft_free_matrix(norm);
	ft_free_matrix(col);
	return (plane);
}
