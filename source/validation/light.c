/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:35:45 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/24 17:41:14 by alicebaghun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.c"

static int	is_valid_light(char **line)
{
	if (!line || ft_strcmp(line[0], "L") != 0)
		return (0);
	if (!line[1] || !line[2] || !line[3] || line[4])
		return (0);
	if (!is_valid_position_vector(line[1]))
		return (0);
	if (!is_valid_brightness_ratio(line[2]))
		return (0);
	if (!is_valid_rgb_argument(line[3]))
		return (0);
	return (1);
}

void	validate_light(char **map, char **line)
{
	if (!is_valid_light(line))
	{
		ft_free_matrix(line);
		ft_free_matrix(map);
		error_handling(INVALID_MAP);
	}
}
