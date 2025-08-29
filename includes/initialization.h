/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:30:19 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/28 21:13:48 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

# include "object_types.h"
#include "validation.h"
# include "libft.h"

# include <stdlib.h>

//objects

t_scene	*initialize_scene(char **map);
void	init_ambient(t_scene *scene, char **line, char **map);
void	init_camera(t_scene *scene, char **line, char **map);
// void	init_light(t_scene *scene, char **line, char **map);
// void	init_sphere(t_scene *scene, char **line, char **map);
// void	init_plane(t_scene *scene, char **line, char **map);
// void	init_cylinder(t_scene *scene, char **line, char **map);
// void	initialize_scene(t_scene *scene, char **map);

// utils
void	free_scene(t_scene *scene);
void	free_scene_inits(t_scene *scene, char **line, char **map);
#endif
