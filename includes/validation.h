/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicebaghunts <alicebaghunts@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:37:25 by alicebaghun       #+#    #+#             */
/*   Updated: 2025/08/24 17:42:08 by alicebaghun      ###   ########.fr       */
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
void	validate_map(char **map);
void	validate_map_line(char **map, char **line);
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
int		is_valid_ambient(char **line);
int		is_valid_camera(char **line);
void	validate_camera(char **map, char **line);
void	validate_ambient(char **map, char **line);
void	validate_light(char **map, char **line);

#endif