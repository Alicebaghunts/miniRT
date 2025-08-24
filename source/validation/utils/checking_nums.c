/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:51:59 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/24 20:11:28 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	is_in_range_float(const char *str, float min, float max)
{
	float	val;

	if (!str)
		return (0);
	val = ft_atof(str);
	if (val < min || val > max)
		return (0);
	return (1);
}

int	is_in_range_int(const char *str, float min, float max)
{
	int	val;

	if (!str)
		return (0);
	val = ft_atoi(str);
	if (val < min || val > max)
		return (0);
	return (1);
}

int	is_valid_float(const char *str)
{
	int	i;
	int	has_dot;

	if (!str || !*str)
		return (0);
	i = 0;
	has_dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 0 && (ft_isdigit(str[i - 1]) || (has_dot && i > 1)))
		return (1);
	else
		return (0);
}

int	is_valid_number(char *num_str)
{
	int	i;

	i = 0;
	if (!num_str)
		return (0);
	if (num_str[0] == '-' || num_str[0] == '+')
		i++;
	while (num_str[i])
	{
		if (!ft_isdigit(num_str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_brightness_ratio(char *line)
{
	if (!is_valid_float(line) || !is_in_range_float(line, 0.0, 1.0))
		return (0);
	return (1);
}
