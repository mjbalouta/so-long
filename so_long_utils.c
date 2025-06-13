/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:13:37 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/13 13:30:48 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	**mapdup(t_map *map)
{
	char	**dup;
	int		i;

	dup = ft_calloc(map->height + 1, sizeof(char *));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		dup[i] = ft_calloc(map->width + 1, sizeof(t_map));
		if (!dup[i])
			return (NULL);
		ft_strlcpy(dup[i], map->map[i], map->width + 1);
		i++;
	}
	return (dup);
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < height)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}