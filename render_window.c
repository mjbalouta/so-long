/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:30:26 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/17 23:07:25 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILE_SIZE 96

void	detect_pressed_key(t_window *window, t_map *map)
{
	int keysym; 
	
	keysym = mlx_key_hook(window->mlx_window, int (*funct_ptr)(), void *param);

}

void	create_img(t_tile *img, t_window *window)
{
	img->water_tile = mlx_xpm_file_to_image(window->mlx_connection, "./textures/water-tile-96.xpm", &img->img_width, &img->img_height);
	img->tile = mlx_xpm_file_to_image(window->mlx_connection, "./textures/new-tile-standard.xpm", &img->img_width, &img->img_height);
	img->squirrel_tile = mlx_xpm_file_to_image(window->mlx_connection, "./textures/squirrel-tile.xpm", &img->img_width, &img->img_height);
	img->bolota_tile = mlx_xpm_file_to_image(window->mlx_connection, "./textures/bolota-tile.xpm", &img->img_width, &img->img_height);
	img->exit_tile = mlx_xpm_file_to_image(window->mlx_connection, "./textures/king-tile.xpm", &img->img_width, &img->img_height);	
}

void	fill_window_map(t_window *window, t_map *map)
{
	int	x;
	int	y;
	t_tile img;

	y = 0;
	create_img(&img, window);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.water_tile, x * TILE_SIZE, y * TILE_SIZE);
			else if (map->map[y][x] == '0')
				mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.tile, x * TILE_SIZE, y * TILE_SIZE);
			else if (map->map[y][x] == 'P')
				mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.squirrel_tile, x * TILE_SIZE, y * TILE_SIZE);
			else if (map->map[y][x] == 'C')
				mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.bolota_tile, x * TILE_SIZE, y * TILE_SIZE);
			else if (map->map[y][x] == 'E')
				mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.exit_tile, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	render_window(t_map *map)
{
	t_window	window;

	window.mlx_connection = mlx_init();
	if (!window.mlx_connection)
		return ;
	window.mlx_window = mlx_new_window(window.mlx_connection, 1920, 1080, "so_long");
	if (!window.mlx_window)
	{
		mlx_destroy_display(window.mlx_connection);
		free(window.mlx_connection);
		return ;
	}
	fill_window_map(&window, map);
	detect_pressed_key(&window, map);
	mlx_loop(window.mlx_connection);
	mlx_destroy_display(window.mlx_connection);
	free(window.mlx_connection);
}
