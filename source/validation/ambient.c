/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:32:57 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/24 17:41:30 by alicebaghun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	is_valid_ambient(char **line)
{
	if (!line || ft_strcmp(line[0], "A") != 0)
		return (0);
	if (!line[1] || !line[2] || line[3])
		return (0);
	if (!is_valid_float(line[1]) || !is_in_range_float(line[1], 0.0, 1.0))
		return (0);
	if (!is_valid_rgb_argument(line[2]))
		return (0);
	return (1);
}

void	validate_ambient(char **map, char **line)
{
	if (!is_valid_ambient(line))
	{
		ft_free_matrix(line);
		ft_free_matrix(map);
		error_handling(INVALID_MAP);
	}
}
