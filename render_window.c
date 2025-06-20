/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:30:26 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/21 16:26:53 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_img(t_game	*game)
{
	game->img->water_tile = mlx_xpm_file_to_image(game->mlx_connection, "./textures/water-tile-96.xpm", &game->img->img_width, &game->img->img_height);
	game->img->tile = mlx_xpm_file_to_image(game->mlx_connection, "./textures/new-tile-standard.xpm", &game->img->img_width, &game->img->img_height);
	game->img->squirrel_tile = mlx_xpm_file_to_image(game->mlx_connection, "./textures/squirrel-tile.xpm", &game->img->img_width, &game->img->img_height);
	game->img->bolota_tile = mlx_xpm_file_to_image(game->mlx_connection, "./textures/bolota-tile.xpm", &game->img->img_width, &game->img->img_height);
	game->img->exit_tile = mlx_xpm_file_to_image(game->mlx_connection, "./textures/king-tile.xpm", &game->img->img_width, &game->img->img_height);	
}

void	fill_window_map(t_game	*game)
{
	int	x;
	int	y;

	y = 0;
	create_img(game);
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img->water_tile, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img->tile, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img->squirrel_tile, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img->bolota_tile, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img->exit_tile, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	mlx_key_hook(game->mlx_window, handle_pressed_key, game);
}

void	render_window(t_game *game)
{
	game->mlx_connection = mlx_init();
	if (!game->mlx_connection)
		return ;
	game->mlx_window = mlx_new_window(game->mlx_connection, game->map->width * TILE_SIZE, game->map->height * TILE_SIZE, "so_long");
	if (!game->mlx_window)
	{
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		return ;
	}
	mlx_hook(game->mlx_window, 17, 0, free_game, game);
	fill_window_map(game);
	mlx_loop(game->mlx_connection);
}
