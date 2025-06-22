/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:02:23 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/22 00:59:57 by mjoao-fr         ###   ########.fr       */
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
	if (map->nr_exit != 1 || map->nr_start != 1 || map->nr_collect < 1)
		return (1);
	if ((validate_first_last_line(map->map, j - 1) != 0) || (validate_path(map, player) == 1))
		return (1);
	return (0);
}

int	check_extension(char *str)
{
	char		*ext;
	
	if (!ft_strncmp(str, ".ber", 5))
		return (1);
	ext = ft_strrchr(str, '.');
	if (!ext)
		return (1);
	if (ext[1] != 'b' || ext[2] != 'e' || ext[3] != 'r' || ext[4])
		return (1);
	return (0);
}
