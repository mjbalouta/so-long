/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:06:25 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/23 18:30:54 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_fill(t_map *dup, t_point current, t_map *map, char to_avoid)
{
	if ((current.x < 0 || current.y < 0 || current.x >= map->width
			|| current.y >= map->height)
		|| dup->map[current.y][current.x] == to_avoid
	|| dup->map[current.y][current.x] == 'F'
	|| dup->map[current.y][current.x] == '1')
		return ;
	if (dup->map[current.y][current.x] == 'C')
		dup->nr_collect++;
	dup->map[current.y][current.x] = 'F';
	first_fill(dup, (t_point){current.x, current.y - 1}, map, 'E');
	first_fill(dup, (t_point){current.x, current.y + 1}, map, 'E');
	first_fill(dup, (t_point){current.x - 1, current.y}, map, 'E');
	first_fill(dup, (t_point){current.x + 1, current.y}, map, 'E');
}

void	second_fill(t_map *dup, t_point current, t_map *map, char to_avoid)
{
	if ((current.x < 0 || current.y < 0 || current.x >= map->width
			|| current.y >= map->height)
		|| dup->map[current.y][current.x] == to_avoid)
		return ;
	if (dup->map[current.y][current.x] == 'E')
		dup->nr_exit++;
	dup->map[current.y][current.x] = '1';
	second_fill(dup, (t_point){current.x, current.y - 1}, map, '1');
	second_fill(dup, (t_point){current.x, current.y + 1}, map, '1');
	second_fill(dup, (t_point){current.x - 1, current.y}, map, '1');
	second_fill(dup, (t_point){current.x + 1, current.y}, map, '1');
}

void	flood_fill(t_map *dup, t_player *player, t_map *map)
{
	int		i;
	int		j;
	t_point	begin;

	ft_memset(&begin, 0, sizeof(t_point));
	dup->map = mapdup(map);
	j = -1;
	while (dup->map[++j])
	{
		i = -1;
		while (dup->map[j][++i])
		{
			if (dup->map[j][i] == 'P')
			{
				player->x = i;
				player->y = j;
				begin.x = i;
				begin.y = j;
				first_fill(dup, begin, map, 'E');
				break ;
			}
		}
	}
	second_fill(dup, begin, map, '1');
}

int	validate_path(t_map *map, t_player *player)
{
	t_map	dup;

	ft_memset(&dup, 0, sizeof(t_map));
	flood_fill(&dup, player, map);
	if (dup.nr_collect != map->nr_collect || dup.nr_exit == 0)
	{
		free_map(dup.map, map->height);
		return (1);
	}
	free_map(dup.map, map->height);
	return (0);
}
