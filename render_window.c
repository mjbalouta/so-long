/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:30:26 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/23 10:31:45 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_img(t_game	*game)
{
	game->img->water = mlx_xpm_file_to_image(game->mlx_connection, "./textures/"
			"water.xpm", &game->img->img_width, &game->img->img_height);
	if (!game->img->water)
		return (1);
	game->img->tile = mlx_xpm_file_to_image(game->mlx_connection,
			"./textures/tile.xpm",
			&game->img->img_width, &game->img->img_height);
	if (!game->img->tile)
		return (1);
	game->img->squirrel = mlx_xpm_file_to_image(game->mlx_connection,
			"./textures/squirrel.xpm", &game->img->img_width,
			&game->img->img_height);
	if (!game->img->squirrel)
		return (1);
	game->img->bolota = mlx_xpm_file_to_image(game->mlx_connection,
			"./textures/bolota.xpm", &game->img->img_width,
			&game->img->img_height);
	if (!game->img->bolota)
		return (1);
	game->img->exit = mlx_xpm_file_to_image(game->mlx_connection,
			"./textures/king.xpm", &game->img->img_width,
			&game->img->img_height);
	if (!game->img->exit)
		return (1);
	return (0);
}

void	put_image_to_window(t_game *game, int x, int y)
{
	if (game->map->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->img->water, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->img->tile, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->img->squirrel, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->img->bolota, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->img->exit, x * TILE_SIZE, y * TILE_SIZE);
}

int	fill_window_map(t_game	*game)
{
	int	x;
	int	y;

	y = -1;
	if (create_img(game) == 1)
		return (1);
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			put_image_to_window(game, x, y);
		}
	}
	mlx_key_hook(game->mlx_window, handle_pressed_key, game);
	return (0);
}

int	handle_close(t_game *game)
{
	mlx_loop_end(game->mlx_connection);
	return (0);
}

int	render_window(t_game *game)
{
	game->mlx_connection = mlx_init();
	if (!game->mlx_connection)
		return (1);
	game->mlx_window = mlx_new_window(game->mlx_connection,
			game->map->width * TILE_SIZE, game->map->height * TILE_SIZE,
			"so_long");
	if (!game->mlx_window)
	{
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		return (1);
	}
	if (fill_window_map(game) == 1)
		return (1);
	mlx_hook(game->mlx_window, 17, 0, &handle_close, game);
	mlx_loop(game->mlx_connection);
	return (0);
}
