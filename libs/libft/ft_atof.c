/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:45:47 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/23 21:51:54 by alicebaghun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_part(const char *s, int *i, double *res)
{
	int		index;
	double	val;

	index = *i;
	val = 0.0;
	while (ft_isdigit(s[index]))
	{
		val = val * 10.0 + (s[index] - '0');
		index++;
	}
	*res = val;
	*i = index;
	return (0);
}

static int	atof_part(const char *s, int *i, double *fraction)
{
	int		index;
	double	val;
	double	div;

	index = *i;
	val = 0.0;
	div = 10.0;
	if (s[index] != '.')
	{
		*fraction = 0.0;
		return (0);
	}
	index++;
	while (ft_isdigit(s[index]))
	{
		val += (s[index] - '0') / div;
		div *= 10.0;
		index++;
	}
	*fraction = val;
	*i = index;
	return (0);
}

double	ft_atof(const char *s)
{
	double	res;
	double	fraction;
	double	sign;
	int		i;

	res = 0.0;
	fraction = 0.0;
	sign = 1.0;
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{ 
		if (s[i] == '-')
			sign = -1.0;
		i++;
	}
	atoi_part(s, &i, &res);
	atof_part(s, &i, &fraction);
	return (sign * (res + fraction));
}
