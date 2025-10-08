/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:18:50 by alisharu          #+#    #+#             */
/*   Updated: 2025/10/08 18:12:07 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:12:10 by alisharu          #+#    #+#             */
/*   Updated: 2025/10/08 14:12:10 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	validate_cone(char **map, char **line)
{
	if (!line[1] || !line[2] || !line[3] || !line[4] || !line[5])
	{
		ft_putstr_fd("Error: invalid cone arguments\n", 2);
		ft_free_matrix(line);
		ft_free_matrix(map);
		error_handling(INVALID_MAP);
	}

	if (!is_valid_position_vector(line[1])
		|| !is_valid_direction_vector(line[2])
		|| !is_valid_diameter(line[3])
		|| !is_valid_diameter(line[4])
		|| !is_valid_rgb_argument(line[5]))
	{
		ft_putstr_fd("Error: invalid cone parameters\n", 2);
		ft_free_matrix(line);
		ft_free_matrix(map);
		error_handling(INVALID_MAP);
	}
	// Extra semantic checks: non-zero axis, angle in (0,89.9], positive height
	{
		char		**axis;
		double		x;
		double		y;
		double		z;
		double		angle_deg;
		double		height;

		axis = ft_split(line[2], ',');
		if (!axis || !axis[0] || !axis[1] || !axis[2])
			return (ft_free_matrix(axis), ft_putstr_fd("Error: invalid cone axis\n", 2),
				ft_free_matrix(line), ft_free_matrix(map), error_handling(INVALID_MAP));
		x = ft_atof(axis[0]);
		y = ft_atof(axis[1]);
		z = ft_atof(axis[2]);
		ft_free_matrix(axis);
		if (fabs(x) < 1e-9 && fabs(y) < 1e-9 && fabs(z) < 1e-9)
			return (ft_putstr_fd("Error: cone axis cannot be zero vector\n", 2),
				ft_free_matrix(line), ft_free_matrix(map), error_handling(INVALID_MAP));
		angle_deg = ft_atof(line[3]);
		if (!(angle_deg > 0.0 && angle_deg <= 89.9))
			return (ft_putstr_fd("Error: cone angle must be in (0, 89.9] degrees\n", 2),
				ft_free_matrix(line), ft_free_matrix(map), error_handling(INVALID_MAP));
		height = ft_atof(line[4]);
		if (height <= 0.0)
			return (ft_putstr_fd("Error: cone height must be positive\n", 2),
				ft_free_matrix(line), ft_free_matrix(map), error_handling(INVALID_MAP));
	}
}
