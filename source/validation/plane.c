/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:04:50 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/24 19:07:19 by alicebaghun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	is_valid_plane(char **line)
{
	if (!line || ft_strcmp(line[0], "pl") != 0)
		return (0);
	if (!line[1] || !line[2] || !line[3] || line[4])
		return (0);
	if (!is_valid_position_vector(line[1]))
		return (0);
	if (!is_valid_position_vector(line[2]))
		return (0);
	if (!is_valid_rgb_argument(line[3]))
		return (0);
	return (1);
}

void	validate_plane(char **map, char **line)
{
	if (!is_valid_plane(line))
	{
		ft_free_matrix(line);
		ft_free_matrix(map);
		error_handling(INVALID_MAP);
	}
}