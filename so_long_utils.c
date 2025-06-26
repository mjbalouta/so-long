/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:13:37 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/26 15:30:48 by mjoao-fr         ###   ########.fr       */
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
		dup[i] = ft_calloc(map->width + 1, sizeof(char));
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

void	free_images(t_game *game)
{
	if (game->img->tile)
		mlx_destroy_image(game->mlx_connection, game->img->tile);
	if (game->img->water)
		mlx_destroy_image(game->mlx_connection, game->img->water);
	if (game->img->squirrel)
		mlx_destroy_image(game->mlx_connection, game->img->squirrel);
	if (game->img->acorn)
		mlx_destroy_image(game->mlx_connection, game->img->acorn);
	if (game->img->exit)
		mlx_destroy_image(game->mlx_connection, game->img->exit);
}

int	free_game(t_game *game)
{
	if (game->map)
	{
		if (game->map->map)
			free_map(game->map->map, game->map->height);
		free(game->map);
	}
	if (game->player)
		free(game->player);
	free_images(game);
	if (game->img)
		free(game->img);
	if (game->mlx_window)
	{
		mlx_clear_window(game->mlx_connection, game->mlx_window);
		mlx_destroy_window(game->mlx_connection, game->mlx_window);
	}
	if (game->mlx_connection)
	{
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
	}
	return (0);
}
