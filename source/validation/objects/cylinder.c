/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:34:15 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/24 20:22:02 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	is_valid_cylinder(char **line)
{
	if (!line || ft_strcmp(line[0], "cy") != 0)
		return (0);
	if (!line[1] || !line[2] || !line[3] || !line[4] || !line[5] || line[6])
		return (0);
	if (!is_valid_position_vector(line[1]))
		return (0);
	if (!is_valid_direction_vector(line[2]))
		return (0);
	if (!is_valid_diameter(line[3]))
		return (0);
	if (!is_valid_diameter(line[4]))
		return (0);
	if (!is_valid_rgb_argument(line[5]))
		return (0);
	return (1);
}

void	validate_cylinder(char **map, char **line)
{
	if (!is_valid_cylinder(line))
	{
		ft_free_matrix(line);
		ft_free_matrix(map);
		error_handling(INVALID_MAP);
	}
}
