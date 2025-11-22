/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:13:57 by alisharu          #+#    #+#             */
/*   Updated: 2025/11/22 17:31:43 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	is_valid_cone(char **line)
{
	if (!line || ft_strcmp(line[0], "co") != 0)
		return (0);
	if (!line[1] || !line[2] || !line[3] || !line[4] || !line[5])
		return (0);
	if (line[7])
		return (0);
	if (line[6] && !ft_is_valid_xpm_path(line[6]))
		return (0);
	if (!is_valid_position_vector(line[1])
		|| !is_valid_direction_vector(line[2]) || !is_valid_float(line[3])
		|| !is_valid_float(line[4]) || !is_valid_rgb_argument(line[5]))
		return (0);
	return (1);
}

void	validate_cone(char **map, char **line)
{
	if (!is_valid_cone(line))
	{
		ft_free_matrix(line);
		ft_free_matrix(map);
		error_handling(INVALID_MAP);
	}
}
