/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:12:05 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/01 20:16:50 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "initialization.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	t_scene	*scene;
}			t_mlx;

double		vector_length(t_vector vector);
double		vec_dot(t_vector a, t_vector b);
t_vector	vec_sub(t_vector a, t_vector b);
t_vector	vec_cross(t_vector a, t_vector b);
t_vector	vec_scale(t_vector v, double s);
t_vector	vector_addition(t_vector a, t_vector b);

#endif
