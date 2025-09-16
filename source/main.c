/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:33:32 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/16 18:41:42 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	error_handling(int num)
{
	if (num == 1)
		ft_putstr_fd("Error: Invalid argument\n", 2);
	else if (num == 2)
		ft_putstr_fd("Error: Invalid path\n", 2);
	else if (num == 3)
		ft_putstr_fd("Error: Failed to open file\n", 2);
	else if (num == 4)
		ft_putstr_fd("Error: Invalid map\n", 2);
	else if (num == 5)
		ft_putstr_fd("Error: Failed to malloc\n", 2);
	exit(num);
}

t_mlx	*mlx_init_scene(t_scene *scene, int width, int height, char *title)
{
	t_mlx	*mlx_struct;

	mlx_struct = malloc(sizeof(t_mlx));
	if (!mlx_struct)
		return (NULL);
	mlx_struct->mlx = mlx_init();
	if (!mlx_struct->mlx)
	{
		free(mlx_struct);
		return (NULL);
	}
	mlx_struct->window = mlx_new_window(mlx_struct->mlx, width, height, title);
	if (!mlx_struct->window)
	{
		free(mlx_struct->mlx);
		free(mlx_struct);
		return (NULL);
	}
	mlx_struct->scene = scene;
	return (mlx_struct);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;
	char	**map_array;
	int		fd;
	t_mlx	*app;

	if (argc != 2)
		error_handling(INVALID_ARGUMENT);
	fd = check_and_open_map_file(argv[1]);
	map_array = read_in_map_file(fd);
	validate_map(map_array);
	scene = initialize_scene(map_array);
	normalize_vectors(scene);
	app = mlx_init_scene(scene, MLX_X, MLX_Y, "miniRT");
	if (!app)
		return (1);
	drawing(app);
	mlx_loop(app->mlx);
}
