/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:59:40 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/12 12:22:52 by mjoao-fr         ###   ########.fr       */
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
	return (map->map);
}

int main(int ac, char **av)
{
	char		*ext;
	int			fd;
	t_map		*map;
	t_player	*player;

	if (ac != 2)
		return (write(2, "Error.\nMissing map.\n", 20));
	ext = ft_strrchr(av[1], '.');
	if (ext[1] != 'b' || ext[2] != 'e' || ext[3] != 'r' || ext[4])
		return (write(2, "Error.\nWrong file. Must be .ber.\n", 33));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "Error.\nCan't read map.\n", 23));
	map = ft_calloc(1, sizeof(t_map));
	player = ft_calloc(1, sizeof(t_player));
	map->map = fill_map(fd, map, av[1]);
	if (!map->map || validate_map(map, player) != 0)
		return (free(map->map), write(2, "Error.\nInvalid map.\n", 20));
	return (0);
}
