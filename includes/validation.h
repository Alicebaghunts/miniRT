/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:34:42 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/24 19:34:45 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "libft.h"
# include "object_types.h"

int		checking_argument(char *str);
int		check_extension(char *path);
void	ft_free_matrix(char **arr);
int		check_and_open_map_file(char *path);
char	**read_in_map_file(int fd);
void	error_handling(int num);

// validation
int		is_valid_diameter(const char *line);
int		is_valid_float(const char *str);
int		is_valid_number(char *num_str);
int		is_valid_fov(char *line);
int		is_in_range_float(const char *str, float min, float max);
int		is_in_range_int(const char *str, float min, float max);
int		is_valid_position_vector(char *line);
int		is_valid_direction_vector(char *line);
int		is_valid_rgb_argument(char *line);
int		is_valid_brightness_ratio(char *line);

// caracters
void	validate_map(char **map);
void	validate_map_line(char **map, char **line);
void	validate_camera(char **map, char **line);
void	validate_ambient(char **map, char **line);
void	validate_light(char **map, char **line);
void	validate_sphere(char **map, char **line);
void	validate_plane(char **map, char **line);
void	validate_cylinder(char **map, char **line);

#endif