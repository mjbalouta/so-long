/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:58:56 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/21 13:06:51 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define KEY_UP 65361
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_ESC 65307

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
		exit(0);
	return (0);
}

void	move_player(t_game *game, int x, int y)
{
	game->player->x += x;
	game->player->y += y;
	fill_window_map(game);
}