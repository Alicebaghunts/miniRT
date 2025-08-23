/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:18:07 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/23 18:44:34 by alicebaghun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

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
	int	i;

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