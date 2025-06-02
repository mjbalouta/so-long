/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:59:40 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/02 18:38:31 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill_map(int fd)
{
	char	*line;
	int		line_size;
	char 	**map;
	int		j;
	char	**temp;

	j = 0;
	map = ft_calloc(1, sizeof(char *));
	if (!map)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		temp = ft_recalloc(map, j * sizeof(char *), j + 2, sizeof(char *));
		if (!temp)
			return (free(map), NULL);
		map = temp;
		line_size = ft_strlen(line);
		map[j] = ft_calloc(line_size + 1, sizeof(char));
		if (!map[j])
			return(NULL);
		ft_strlcpy(map[j], line, line_size + 1);
		j++;
	}
	if (validate_map(map) != 0)
		return (NULL);
	return (map);
}

int main(int ac, char **av)
{
	char	*ext;
	int		fd;
	char	**map;

	if (ac != 2)
		return (write(2, "Error.\nMissing map.\n", 20));
	ext = ft_strrchr(av[1], '.');
	if (ext[1] != 'b' || ext[2] != 'e' || ext[3] != 'r' || ext[4])
		return (write(2, "Error.\nWrong file. Must be .ber.\n", 33));
	fd = open(av[1], O_RDONLY);
	if (fd == - 1)
		return (write(2, "Error.\nCan't read map.\n", 23));
	map = fill_map(fd);
	if (!map)
		return (free(map), write(2, "Error.\nInvalid map.\n", 20));
	return (0);
}
