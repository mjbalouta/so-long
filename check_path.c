/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:06:25 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/23 14:36:12 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **dup, t_point current, t_map *map, char to_avoid1)
{
	if ((current.x < 0 || current.y < 0 || current.x >= map->width
			|| current.y >= map->height)
		|| dup[current.y][current.x] == to_avoid1
	|| dup[current.y][current.x] == 'E')
		return ;
	dup[current.y][current.x] = '1';
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
		ft_printf("before: %s\n", dup[j]);
	}
	j = 0;
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
		ft_printf("after: %s\n", dup[j]);
		j++;
	}
	return (dup);
}

int	validate_path(t_map *map, t_player *player)
{
	char	**dup;
	int		i;
	int		j;

	dup = flood_fill(map, player);
	j = 0;
	i = 0;
	while (dup[j])
	{
		i = 0;
		while (dup[j][i])
		{
			if (dup[j][i] == 'C')
				return (free_map(dup, map->height), 1);
			i++;
		}
		j++;
	}
	free_map(dup, map->height);
	return (0);
}
