/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:59:15 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/21 13:10:03 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./libft-projects/get-next-line/get_next_line.h"
#include "./libft-projects/libft/libft.h"
#include "./libft-projects/printf/libftprintf.h"
#include "./minilibx-linux/mlx.h"

typedef struct    s_map
{
	char	**map;
    int		nr_exit;
	int		nr_start;
	int		nr_collect;
	int		width;
	int		height;
}                 t_map;

typedef struct s_player
{
	int	x;
	int y;
	int collected;
}					t_player;

typedef struct s_tile
{
	int		img_width;
	int		img_height;
	void	*tile;
	void	*water_tile;
	void	*squirrel_tile;
	void	*bolota_tile;
	void	*exit_tile;	
}				t_tile;

typedef	struct s_game
{
	void		*mlx_connection;
	void		*mlx_window;
	t_player	*player;
	t_map		*map;
}				t_game;

typedef struct s_point
{
	int x;
	int y;
}				t_point;

char	**fill_map(int fd, t_map *map, char *file);
int		validate_chars(char *str, int curr_size, t_map *map);
int		validate_first_last_line(char **map, int j);
void	fill(char **dup, t_point current, t_map *map, char to_avoid);
char	**flood_fill(t_map *map, t_player *player);
int		validate_path(t_map *map, t_player *player);
int		validate_map(t_map *map, t_player *player);
int		check_extension(char *str);
int		line_len(char *str);
char	**mapdup(t_map *map);
void	free_map(char **map, int height);
void	free_game(t_game *game);
void	fill_window_map(t_game *game);
void	render_window(t_game *game);
void	create_img(t_tile *img, t_game *game);
int		handle_pressed_key(int keysym, t_game *game);
void	move_player(t_game *game, int x, int y);

#endif