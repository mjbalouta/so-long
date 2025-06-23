/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:06:25 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/23 15:18:11 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **dup, t_point current, t_map *map, char to_avoid1)
{
	//contar se existe o E aqui e guardar numa variavel e preencher na mesma o E com R
	if ((current.x < 0 || current.y < 0 || current.x >= map->width
			|| current.y >= map->height)
		|| dup[current.y][current.x] == to_avoid1
	|| dup[current.y][current.x] == 'E'
	|| dup[current.y][current.x] == 'R')
		return ;
	dup[current.y][current.x] = 'R';
	fill(dup, (t_point){current.x, current.y - 1}, map, '1');
	fill(dup, (t_point){current.x, current.y + 1}, map, '1');
	fill(dup, (t_point){current.x - 1, current.y}, map, '1');
	fill(dup, (t_point){current.x + 1, current.y}, map, '1');
}

char	**flood_fill(t_map *map, t_player *player)
{
	char	**dup;
	int		i;
	int		j;
	t_point	begin;

	dup = mapdup(map);
	j = -1;
	while (dup[++j])
	{
		i = 0;
		while (dup[j][i])
		{
			if (dup[j][i] == 'P')
			{
				player->x = i;
				player->y = j;
				begin.x = i;
				begin.y = j;
				fill(dup, begin, map, '1');
				break ;
			}
			i++;
		}
	}
	j = 0;
	while (dup[j])
	{
		ft_printf("%s\n", dup[j]);
		j++;
	}
	return (dup);
}

int	validate_path(t_map *map, t_player *player)
{
	char	**dup;
	int		i;
	int		j;
	int		count_c;
	int		count_e;

	dup = flood_fill(map, player);
	j = 0;
	i = 0;
	count_c = 0;
	count_e = 0;
	while (dup[j])
	{
		i = 0;
		while (dup[j][i])
		{
			if (dup[j][i] == 'C')
				count_c++;
			if (dup[j][i] == 'E')
				count_e++;
			i++;
		}
		j++;
	}
	if (!count_e && !count_c)
		return (free_map(dup, map->height), 1);
	free_map(dup, map->height);
	return (0);
}
