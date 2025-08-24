/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:33:49 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/24 19:33:50 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	is_valid_sphere(char **line)
{
	if (!line || ft_strcmp(line[0], "sp") != 0)
		return (0);
	if (!line[1] || !line[2] || !line[3] || line[4])
		return (0);
	if (!is_valid_position_vector(line[1]))
		return (0);
	if (!is_valid_diameter(line[2]))
		return (0);
	if (!is_valid_rgb_argument(line[3]))
		return (0);
	return (1);
}

void	validate_sphere(char **map, char **line)
{
	if (!is_valid_sphere(line))
	{
		ft_free_matrix(line);
		ft_free_matrix(map);
		error_handling(INVALID_MAP);
	}
}