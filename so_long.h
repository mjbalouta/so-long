/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:59:15 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/11 17:07:17 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./libft-projects/get-next-line/get_next_line.h"
#include "./libft-projects/libft/libft.h"
#include "./libft-projects/printf/libftprintf.h"

typedef struct    s_map
{
	char	**map;
    int		nr_exit;
	int		nr_start;
	int		nr_collect;
	int		width;
	int		height;
}                 t_map;

char	**fill_map(int fd, t_map *map);
int		validate_chars(char *str, int curr_size, t_map *map);
int		validate_first_last_line(char **map, int j);
int		validate_map(t_map *map);
int		line_len(char *str);

#endif