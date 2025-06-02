/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:59:40 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/02 15:10:08 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill_map(int fd)
{
	char	*line;
	int		i;
	char 	**map;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	while ((line = get_next_line(fd)))
	{
		temp = ft_recalloc(map, i, i + 1, sizeof(char *));
		if (!temp)
			return (free(map), NULL);
		map = temp;
		i = ft_strlen(line);
		map[j] = ft_calloc((i + 1), sizeof(char));
		if (!*map[j])
			return(NULL);
		ft_strlcpy(map[j], line, i + 1);
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
		return (write(2, "Error.\nMissing map.", 19));
	ext = ft_strrchr(av[1], '.');
	if (ext[1] != 'b' || ext[2] != 'e' || ext[3] != 'r' || ext[4])
		return (write(2, "Error.\nWrong file. Must be .ber.", 32));
	fd = open(av[1], O_RDONLY);
	if (fd == - 1)
		return (write(2, "Error.\nCan't read map.", 22));
	map = fill_map(fd);
	if (!map)
		return (write(2, "Error.\nInvalid map.", 19));
	return (0);
}
