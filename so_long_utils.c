/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:13:37 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/11 20:06:12 by mjoao-fr         ###   ########.fr       */
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

	dup = ft_calloc(map->height + 1, sizeof(t_map));
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