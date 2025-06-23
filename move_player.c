/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:58:56 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/23 10:58:02 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_pressed_key(int keysym, t_game *game)
{
	if (keysym == KEY_UP)
		move_player(game, 0, -1);
	else if (keysym == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keysym == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keysym == KEY_RIGHT)
		move_player(game, 1, 0);
	else if (keysym == KEY_ESC)
	{
		free_game(game);
		exit(0);
	}
	return (0);
}

void	check_moves(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player->x + x;
	new_y = game->player->y + y;
	if (game->map->map[new_y][new_x] == '1')
	{
		ft_printf("%sYou can't swim%s\n", CYAN, DEFAULT);
		return ;
	}
	if (game->map->map[new_y][new_x] == 'C')
		game->player->collected++;
	game->map->map[game->player->y][game->player->x] = '0';
	game->map->map[game->player->y + y][game->player->x + x] = 'P';
	game->player->x += x;
	game->player->y += y;
	game->moves++;
}

void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player->x + x;
	new_y = game->player->y + y;
	if (game->player->collected == game->map->nr_collect)
		ft_printf("%sOnly the queen of acrons left.%s\n", YELLOW, DEFAULT);
	if (game->map->map[new_y][new_x] == '0'
			|| game->map->map[new_y][new_x] == 'C'
		|| game->map->map[new_y][new_x] == '1')
		check_moves(game, x, y);
	else
	{
		if (game->map->map[new_y][new_x] == 'E'
				&& game->player->collected == game->map->nr_collect)
			ft_printf("%sYOU WON! Congrats.%s\n", GREEN, DEFAULT);
		else
			ft_printf("%sYOU LOST! You must collect all acorns"
				" before collecting the king of acorns.%s\n", RED, DEFAULT);
		free_game(game);
		exit(0);
	}
	ft_printf("You moved %d time(s).\n", game->moves);
	free_images(game);
	fill_window_map(game);
}
