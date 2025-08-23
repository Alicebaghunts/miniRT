/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:41:32 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/23 18:43:45 by alicebaghun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_TYPES_H
# define OBJECT_TYPES_H
# include "libft.h"

#define INVALID_ARGUMENT 1
#define INVALID_PATH 2
#define INVALID_FILE 3
#define INVALID_MAP 4
#define MALLOC_ERROR 5

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_ambient
{
	double	light_ratio;
	t_color	color;
}	t_ambient;

typedef struct s_camera
{
	t_vector	position;
	t_vector	direction;
	int			field_of_view;
}	t_camera;

typedef struct s_light
{
	t_vector	position;
	double		brightness_ratio;
	t_color		color;
}	t_light;

typedef struct s_sphere
{
	t_vector	position;
	double		diameter;
	t_color		color;
}	t_sphere;

typedef struct s_plane
{
	t_vector	position;
	t_vector	normal;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	position;
	t_vector	direction;
	double		diameter;
	double		height;
	t_color		color;
}	t_cylinder;

typedef union u_object_data
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_object_data;

typedef struct s_object
{
	char			type;
	t_object_data	data;
}	t_object;

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_list		*lights;
	t_list		*objects;
}	t_scene;

#endif
