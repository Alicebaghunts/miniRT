/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:31:27 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/24 18:56:40 by alicebaghun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

// sp 0,2,9 4 0,255,255
// sp 0,0,12 5 0,255,0 
// sp 2,-2,9 2 255,255,0

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