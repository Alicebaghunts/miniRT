/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:55:25 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/21 22:56:45 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "object_types.h"
# include <math.h>

t_vector    vector_addition(t_vector a, t_vector b);
t_vector    vector_sub(t_vector a, t_vector b);
t_vector    vector_scale(t_vector a, double s);
double      vector_dot(t_vector a, t_vector b);
t_vector    vector_cross(t_vector a, t_vector b);
double      vector_length(t_vector v);

#endif
