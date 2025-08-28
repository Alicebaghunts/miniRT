/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:29:37 by alisharu          #+#    #+#             */
/*   Updated: 2025/08/28 19:51:26 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

t_color *parse_color(char *line)
{
    t_color *color;
    char    **matrix_color;

    if (!line)
        error_handling(INVALID_MAP);
    matrix_color = ft_split(line, ',');
    if (!matrix_color)
        error_handling(MALLOC_ERROR);
    color->red = ft_atoi(matrix_color[0]);
    color->green = ft_atoi(matrix_color[1]);
    color->blue = ft_atoi(matrix_color[2]);
    ft_free_ma
    color = ft_calloc(1, sizeof(t_color));
    if (!color)
        error_handling(MALLOC_ERROR);
    

}

void	init_ambient(t_scene *scene, char **line)
{
	if (scene->ambient != NULL)
		error_handling(INVALID_MAP);
	scene->ambient = ft_calloc(1, sizeof(t_ambient));
	if (!scene->ambient)
		error_handling(MALLOC_ERROR);
	scene->ambient->light_ratio = ft_atof(line[1]);
	scene->ambient->color = parse_color(line[2]);
}

void	fill_scene_with_line(t_scene *scene, char **line)
{
	if (!scene || !line || !line[0])
		return ;
	if (ft_strcmp(line[0], "A") == 0)
		init_ambient(scene, line);
	else if (ft_strcmp(line[0], "C") == 0)
		init_camera(scene, line);
	else if (ft_strcmp(line[0], "L") == 0)
		init_light(scene, line);
	else if (ft_strcmp(line[0], "sp") == 0)
		init_sphere(scene, line);
	else if (ft_strcmp(line[0], "pl") == 0)
		init_plane(scene, line);
	else if (ft_strcmp(line[0], "cy") == 0)
		init_cylinder(scene, line);
}

void	initialize_scene(t_scene *scene, char **map)
{
	t_scene *scene;
	char **split_line;
	int i;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		error_handling(MALLOC_ERROR);
	scene->ambient = NULL;
	scene->camera = NULL;
	scene->lights = NULL;
	scene->objects = NULL;
	i = -1;
	while (map[++i])
	{
		split_line = ft_split(map[i], ' ');
		if (!split_line)
			error_handling(MALLOC_ERROR);
		fill_scene_with_line(scene, split_line);
		ft_free_matrix(split_line);
	}
	return (scene);
}