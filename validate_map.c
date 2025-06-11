/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:02:23 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/07 17:03:12 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*validate_chars(char *map, int curr_size)
{
	int i;
	
	i = 0;
	while (map[i] != '\n' && map[i])
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'C' && map[i] != 'E' && map[i] != 'P')
			return (NULL);
		if ((i == 0 || i == (curr_size - 1)) && map[i] != '1')
			return (NULL);
		if (map[i] == 'E')
			ex_st_col[0] += 1;
		else if (map[i] == 'P')
			ex_st_col[1] += 1;
		else if (map[i] == 'C')
			ex_st_col[2] += 1;
		i++;
	}
	return (ex_st_col);
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

int validate_map(char **map)
{
	int j;
	int curr_size;
	int prev_size;

	j = 0;
	prev_size = 0;
	curr_size = 0;
	while (map[j])
	{
		curr_size = line_len(map[j]);
		if (prev_size != 0 && curr_size != prev_size)
			return (1);
		validate_chars(map[j], ex_st_col, curr_size);
		if (!ex_st_col)
			return (1);
		prev_size = curr_size;
		j++;
	}
	if (validate_first_last_line(map, j - 1) != 0)
		return (1);
	if (ex_st_col[0] != 1 || ex_st_col[1] != 1 || ex_st_col[2] < 1)
		return (1);
	return (0);
}
