/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:30:19 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/01 00:14:27 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

# include "libft.h"
# include "object_types.h"
# include "validation.h"
# include <stdlib.h>

// objects

t_scene		*initialize_scene(char **map);
void		init_ambient(t_scene *scene, char **line, char **map);
void		init_camera(t_scene *scene, char **line, char **map);
void		init_light(t_scene *scene, char **line, char **map);

t_cylinder	*init_cylinder(char **line);
t_plane		*init_plane(char **line);
// void	init_sphere(t_scene *scene, char **line, char **map);
// void	initialize_scene(t_scene *scene, char **map);

//
t_color		*parse_color(char *line);
t_vector	*init_vector(char *line);

// utils

void		free_scene(t_scene *scene);
void		free_light(void *content);
void		free_object(void *content);
void		free_scene_inits(t_scene *scene, char **line, char **map);
void		init_objects(t_scene *scene, char **line, char **map);
int			cmp_types_and_init(char **line, t_object *object);

#endif
