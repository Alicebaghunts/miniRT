/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:37:25 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/23 18:47:19 by alicebaghun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

#include "object_types.h"
#include "libft.h"

int	    checking_argument(char *str);
int	    check_extension(char *path);
void	ft_free_matrix(char **arr);
int 	check_and_open_map_file(char *path);
char	**read_in_map_file(int fd);
void	error_handling(int num);

#endif