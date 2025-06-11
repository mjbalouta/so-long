/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:02:23 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/12 00:30:41 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_chars(char *str, int curr_size, t_map *map)
{
	int i;
	
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C' && str[i] != 'E' && str[i] != 'P')
			return (1);
		if ((i == 0 || i == (curr_size - 1)) && str[i] != '1')
			return (1);
		if (str[i] == 'E')
			map->nr_exit++;
		else if (str[i] == 'P')
			map->nr_start++;
		else if (str[i] == 'C')
			map->nr_collect++;
		i++;
	}
	return (0);
}

int	validate_first_last_line(char **map, int j)
{
	int	i;

	i = 0;
	while (map[0][i] && map[0][i] != '\n')
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map[j][i] && map[j][i] != '\n')
	{
		if (map[j][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	fill(char **dup, t_point current, t_map *map, char to_avoid)
{
	if (current.x < 0 || current.y < 0 || current.x >= map->width || current.y >= map->height || dup[current.x][current.y] == to_avoid)
		return ;
	
	dup[current.x][current.y] = '1';

	fill(dup, (t_point){current.y, current.x - 1}, map, '1');
	fill(dup, (t_point){current.y, current.x + 1}, map, '1');
	fill(dup, (t_point){current.y - 1, current.x}, map, '1');
	fill(dup, (t_point){current.y + 1, current.x}, map, '1');	
}

char	**flood_fill(t_map *map, t_player *player)
{
	char	**dup;
	int		i;
	int		j;
	t_point	begin;
	
	dup = mapdup(map);
	i = 0;
	j = 0;
	while (dup[j])
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
				fill(dup, begin, map, '1'); //seg fault (maybe pq height é 7 e devia ser 6)
				break ;
			}
			i++;
		}
		j++;
	}
	j = 0;
	while (dup[j])
	{
		ft_printf("%s\n", dup[j]);
		j++;
	}
	return (dup);
	//verificar se é possível apanhar todos os 'c' e chegar ao 'e'
}

int validate_map(t_map *map, t_player *player)
{
	int j;
	int curr_size;
	int prev_size;

	j = 0;
	prev_size = 0;
	curr_size = 0;
	while (map->map[j])
	{
		curr_size = line_len(map->map[j]);
		if (prev_size != 0 && curr_size != prev_size)
			return (1);
		if (validate_chars(map->map[j], curr_size, map) == 1)
			return (1);
		prev_size = curr_size;
		j++;
	}
	map->width = curr_size;
	if (validate_first_last_line(map->map, j - 1) != 0)
		return (1);
	if (map->nr_exit != 1 || map->nr_start != 1 || map->nr_collect < 1)
		return (1);
	flood_fill(map, player);
	return (0);
}
