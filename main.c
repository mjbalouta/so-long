/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:59:40 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/26 15:44:55 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill_map(int fd, t_map *map, char *file)
{
	char	*line;
	int		j;

	j = 0;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->height++;
	}
	free(line);
	map->map = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->map)
		return (NULL);
	close(fd);
	fd = open(file, O_RDONLY);
	while (j < map->height)
		map->map[j++] = get_next_line(fd);
	line = get_next_line(fd);
	free(line);
	close(fd);
	return (map->map);
}

int	init_structs(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (1);
	ft_memset(game->map, 0, sizeof(t_map));
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		return (1);
	ft_memset(game->player, 0, sizeof(t_player));
	game->img = malloc(sizeof(t_tile));
	if (!game->img)
		return (1);
	ft_memset(game->img, 0, sizeof(t_tile));
	return (0);
}

int	main(int ac, char **av)
{
	int			fd;
	t_game		game;

	if (ac != 2)
		return (ft_printf("%sError\nMissing map.%s\n", RED, DEFAULT));
	if (check_extension(av[1]) == 1)
		return (ft_printf("%sError\nMust be <name>.ber.%s\n", RED, DEFAULT));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("%sError\nCan't read map.%s\n", RED, DEFAULT));
	if (init_structs(&game) != 0)
		return (ft_printf("%sError\nCan't allocate memory.%s\n"
				, RED, DEFAULT));
	game.map->map = fill_map(fd, game.map, av[1]);
	if (!game.map->map || validate_map(game.map, game.player) == 1)
		return (free_game(&game), ft_printf("%sError\nInvalid Map.%s\n"
				, RED, DEFAULT));
	if (render_window(&game) == 1)
		return (free_game(&game), ft_printf("%sError\nCan't render window.%s\n"
				, RED, DEFAULT));
	free_game(&game);
	return (0);
}
