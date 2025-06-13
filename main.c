/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:59:40 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/13 14:53:58 by mjoao-fr         ###   ########.fr       */
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

int main(int ac, char **av)
{
	int			fd;
	t_map		map;
	t_player	player;
	t_window	window;

	if (ac != 2)
		return (write(2, "Error.\nMissing map.\n", 20));
	check_extension(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "Error.\nCan't read map.\n", 23));
	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&player, 0, sizeof(t_map));
	map.map = fill_map(fd, &map, av[1]);
	if (!map.map || validate_map(&map, &player) == 1)
		return (free_map(map.map, map.height), write(2, "Error.\nInvalid map.\n", 20));
	window.mlx_connection = mlx_init();
	window.mlx_window = mlx_new_window(window.mlx_connection, 1920, 1080, "so_long");
	window.img = mlx_new_image(window.mlx_connection, 1920, 1080);
	mlx_loop(window.mlx_connection);
	free_map(map.map, map.height);
	return (0);
}
