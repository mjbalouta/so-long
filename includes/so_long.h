/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:59:15 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/10/29 15:27:39 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 96
# define KEY_LEFT  65361
# define KEY_UP    65362
# define KEY_RIGHT 65363
# define KEY_DOWN  65364
# define KEY_ESC   65307

//\033[<STYLE>;<TEXT_COLOR>;<BACKGROUND_COLOR>m
# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define DEFAULT "\033[0m"
# define YELLOW "\033[38;5;178m"

# include "get_next_line.h"
# include "libft.h"
# include "libftprintf.h"
# include "mlx.h"

typedef struct s_map
{
	char	**map;
	int		nr_exit;
	int		nr_start;
	int		nr_collect;
	int		width;
	int		height;
}			t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	collected;
}			t_player;

typedef struct s_tile
{
	int		img_width;
	int		img_height;
	void	*tile;
	void	*water;
	void	*squirrel;
	void	*acorn;
	void	*exit;	
}				t_tile;

typedef struct s_game
{
	void		*mlx_connection;
	void		*mlx_window;
	t_player	*player;
	t_map		*map;
	t_tile		*img;
	int			moves;
}				t_game;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

char	**fill_map(int fd, t_map *map, char *file);
int		validate_chars(char *str, int curr_size, t_map *map);
int		validate_first_last_line(char **map, int j);
void	first_fill(t_map *dup, t_point current, t_map *map, char to_avoid);
void	second_fill(t_map *dup, t_point current, t_map *map, char to_avoid);
void	flood_fill(t_map *dup, t_player *player, t_map *map);
int		validate_path(t_map *map, t_player *player);
int		validate_map(t_map *map, t_player *player);
int		check_extension(char *str);
int		line_len(char *str);
char	**mapdup(t_map *map);
void	free_map(char **map, int height);
int		free_game(t_game *game);
void	put_image_to_window(t_game *game, int x, int y);
int		fill_window_map(t_game *game);
int		render_window(t_game *game);
int		create_img(t_game *game);
int		handle_pressed_key(int keysym, t_game *game);
void	move_player(t_game *game, int x, int y);
void	check_moves(t_game *game, int x, int y);
void	check_win_or_loss(t_game *game, int x, int y);
void	free_images(t_game *game);
int		init_structs(t_game *game);
int		handle_close(t_game *game);

#endif