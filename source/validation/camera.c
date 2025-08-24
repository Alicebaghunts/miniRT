/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:18:26 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/24 17:41:26 by alicebaghun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	is_valid_camera(char **line)
{
	if (!line || ft_strcmp(line[0], "C") != 0)
		return (0);
	if (!line[1] || !line[2] || !line[3] || line[4])
		return (0);
	if (!is_valid_position_vector(line[1]))
		return (0);
	if (!is_valid_direction_vector(line[2]))
		return (0);
	if (!is_valid_fov(line[3]))
		return (0);
	return (1);
}

void	validate_camera(char **map, char **line)
{
	if (!is_valid_camera(line))
	{
		ft_free_matrix(line);
		ft_free_matrix(map);
		error_handling(INVALID_MAP);
	}
}
