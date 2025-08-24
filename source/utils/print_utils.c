/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:34:34 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/24 19:34:36 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_types.h"

void	error_handling(int num)
{
	if (num == 1)
		ft_putstr_fd("Error: Invalid argument\n", 2);
	else if (num == 2)
		ft_putstr_fd("Error: Invalid path\n", 2);
	else if (num == 3)
		ft_putstr_fd("Error: Failed to open file\n", 2);
	else if (num == 4)
		ft_putstr_fd("Error: Invalid map\n", 2);
	else if (num == 5)
		ft_putstr_fd("Error: Failed to malloc\n", 2);
	exit(num);
}
