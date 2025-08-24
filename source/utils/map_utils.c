/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:34:30 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/24 19:34:31 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "validation.h"

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	double	fraction;
	double	divisor;
	int		i;

	result = 0.0;
	sign = 1.0;
	fraction = 0.0;
	divisor = 10.0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			fraction += (str[i] - '0') / divisor;
			divisor *= 10.0;
			i++;
		}
	}
	return (sign * (result + fraction));
}

int	checking_argument(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int	check_extension(char *path)
{
	char	*dot;

	dot = ft_strrchr(path, '.');
	if (!dot || ft_strcmp(dot, ".rt"))
		return (0);
	return (1);
}

void	ft_free_matrix(char **arr)
{
	int i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}
