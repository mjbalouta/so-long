/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:59:15 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/17 22:25:29 by mjoao-fr         ###   ########.fr       */
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

typedef struct s_point
{
	int x;
	int y;
}				t_point;

typedef	struct s_window
{
	void	*mlx_connection;
	void	*mlx_window;
}				t_window;

typedef struct s_tile
{
	int		img_width;
	int		img_height;
	void	*tile;
	void	*water_tile;
	void	*squirrel_tile;
	void	*bolota_tile;
	void	*exit_tile;
	// void	*right_tile01;
	// void	*right_tile02;
	// void	*right_tile03;
	// void	*right_tile04;
	// void	*left_tile01;
	// void	*left_tile02;
	// void	*left_tile03;
	// void	*left_tile04;
	// void	*top_left_corner;
	// void	*top;
	// void	*top_right_corner;
	// void	*right;
	// void	*bottom_right_corner;
	// void	*bottom;
	// void	*bottom_left_corner;
	// void	*left;
	
}				t_tile;

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
void	fill_window_map(t_window *window, t_map *map);
void	render_window(t_map *map);
void	create_img(t_tile *img, t_window *window);

#endif