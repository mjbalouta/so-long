/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:30:26 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/17 22:25:47 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILE_SIZE 96

void	create_img(t_tile *img, t_window *window)
{
	img->water_tile = mlx_xpm_file_to_image(window->mlx_connection, "./textures/water-tile-96.xpm", &img->img_width, &img->img_height);
	img->tile = mlx_xpm_file_to_image(window->mlx_connection, "./textures/new-tile-standard.xpm", &img->img_width, &img->img_height);
	img->squirrel_tile = mlx_xpm_file_to_image(window->mlx_connection, "./textures/squirrel-tile.xpm", &img->img_width, &img->img_height);
	img->bolota_tile = mlx_xpm_file_to_image(window->mlx_connection, "./textures/bolota-tile.xpm", &img->img_width, &img->img_height);
	img->exit_tile = mlx_xpm_file_to_image(window->mlx_connection, "./textures/king-tile.xpm", &img->img_width, &img->img_height);
	// img->right_tile01 = mlx_xpm_file_to_image(window->mlx_connection, "./textures/right-tiles-01.xpm", &img->img_width, &img->img_height);
	// img->right_tile02 = mlx_xpm_file_to_image(window->mlx_connection, "./textures/right-tiles-02.xpm", &img->img_width, &img->img_height);
	// img->right_tile03 = mlx_xpm_file_to_image(window->mlx_connection, "./textures/right-tiles-03.xpm", &img->img_width, &img->img_height);
	// img->right_tile04 = mlx_xpm_file_to_image(window->mlx_connection, "./textures/right-tiles-04.xpm", &img->img_width, &img->img_height);
 	// img->left_tile01 = mlx_xpm_file_to_image(window->mlx_connection, "./textures/left-tiles-01.xpm", &img->img_width, &img->img_height);
 	// img->left_tile02 = mlx_xpm_file_to_image(window->mlx_connection, "./textures/left-tiles-02.xpm", &img->img_width, &img->img_height);
	// img->left_tile03 = mlx_xpm_file_to_image(window->mlx_connection, "./textures/left-tiles-03.xpm", &img->img_width, &img->img_height);
 	// img->left_tile04 = mlx_xpm_file_to_image(window->mlx_connection, "./textures/left-tiles-04.xpm", &img->img_width, &img->img_height);
	// img->top_left_corner = mlx_xpm_file_to_image(window->mlx_connection, "./textures/top-left-corner.xpm", &img->img_width, &img->img_height);
	// img->top = mlx_xpm_file_to_image(window->mlx_connection, "./textures/top.xpm", &img->img_width, &img->img_height);
	// img->top_right_corner = mlx_xpm_file_to_image(window->mlx_connection, "./textures/top-right-corner.xpm", &img->img_width, &img->img_height);
	// img->right = mlx_xpm_file_to_image(window->mlx_connection, "./textures/right.xpm", &img->img_width, &img->img_height);
	// img->bottom_right_corner = mlx_xpm_file_to_image(window->mlx_connection, "./textures/bottom-right-corner.xpm", &img->img_width, &img->img_height);
	// img->bottom = mlx_xpm_file_to_image(window->mlx_connection, "./textures/bottom.xpm", &img->img_width, &img->img_height);
	// img->bottom_left_corner = mlx_xpm_file_to_image(window->mlx_connection, "./textures/bottom-left-corner.xpm", &img->img_width, &img->img_height);
	// img->left = mlx_xpm_file_to_image(window->mlx_connection, "./textures/left.xpm", &img->img_width, &img->img_height);
	
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
			// if (x == 0 && y == 0)
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.top_left_corner, x * TILE_SIZE, y * TILE_SIZE);
			// else if (x > 0 && x < (map->width - 1) && y == 0)
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.top, x * TILE_SIZE, y * TILE_SIZE);
			// else if (x == (map->width - 1) && y == 0)
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.top_right_corner, x * TILE_SIZE, y * TILE_SIZE);
			// else if (x == (map->width - 1) && y > 0 && y < (map->height - 1))
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.right, x * TILE_SIZE, y * TILE_SIZE);
			// else if (x == (map->width - 1) && y == (map->height - 1))
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.bottom_right_corner, x * TILE_SIZE, y * TILE_SIZE);
			// else if (x > 0 && x < (map->width - 1) && y == (map->height - 1))
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.bottom, x * TILE_SIZE, y * TILE_SIZE);
			// else if (x == 0 && y == (map->height - 1))
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.bottom_left_corner, x * TILE_SIZE, y * TILE_SIZE);
			// else if (x == 0 && y > 0 && y < (map->height - 1))
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.left, x * TILE_SIZE, y * TILE_SIZE);
			// // lado esquerdo	
			// if (x == 0 && y % 4 == 0 && y != 0 && y != (map->height - 1))
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.left_tile04, x * TILE_SIZE, y * TILE_SIZE);
			// else if (x == 0 && y % 3 == 0 && y != 0 && y != (map->height - 1))
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.left_tile03, x * TILE_SIZE, y * TILE_SIZE);
			// else if (x == 0 && y % 2 == 0 && y != 0 && y != (map->height - 1))
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.left_tile02, x * TILE_SIZE, y * TILE_SIZE);
			// else if (x == 0 && y % 1 == 0 && y != 0 && y != (map->height - 1))
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.left_tile01, x * TILE_SIZE, y * TILE_SIZE);
			// //lado direito
			// else if (x == (map->width - 1) && y % 4 == 0 && y != 0 && y != (map->height - 1))
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.right_tile04, x * TILE_SIZE, y * TILE_SIZE);
			// else if (x == (map->width - 1) && y % 3 == 0 && y != 0 && y != (map->height - 1))
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.right_tile03, x * TILE_SIZE, y * TILE_SIZE);
			// else if (x == (map->width - 1) && y % 2 == 0 && y != 0 && y != (map->height - 1))
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.right_tile02, x * TILE_SIZE, y * TILE_SIZE);
			// else if (x == (map->width - 1) && y % 1 == 0 && y != 0 && y != (map->height - 1))
			// 	mlx_put_image_to_window(window->mlx_connection, window->mlx_window, img.right_tile01, x * TILE_SIZE, y * TILE_SIZE);
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
	mlx_loop(window.mlx_connection);
	mlx_destroy_display(window.mlx_connection);
	free(window.mlx_connection);
}