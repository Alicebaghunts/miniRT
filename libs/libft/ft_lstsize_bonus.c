/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:29:12 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/24 19:41:56 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		size;

	tmp = lst;
	size = 0;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp -> next;
	}
	return (size);
}
