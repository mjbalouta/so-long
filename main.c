/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:59:40 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/05/29 15:49:47 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill_map(fd)
{
	char	*line;
	int		i;
	char 	**map;
	int		j;

	i = 0;
	j = 0;
	while ((line = get_next_line(fd)) > 0)
	{
		while (line[i])
			i++;
		*map[j] = ft_calloc((i + 1), sizeof(char));
		if (!*map[j])
			return(NULL);
		i = 0;
		while (line[i])
		{
			map[j][i] = line[i];
			i++;
		}
	}
	return (map);
}

int validate_size_of_lines(char **map, int i, int j)
{
	int i;
	int j;

	i = 0;
	j = 0;
}

int	validate_map(char **map)
{
	int i;
	int j;
	int curr_size;
	int prev_size;

	i = 0;
	j = 0;
	while (*map[j])
	{
		curr_size = ft_strlen(map[j]);
		if (prev_size != 0 && curr_size != prev_size)
			return (write(2, "Error./nInvalid map.", 19));
		while (map[j][i])
		{
			//verifica se encontra algum caracter não permitido
			if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'C' && map[j][i] != 'E' && map[j][i] != 'P')
				return (write(2, "Error./nInvalid map.", 19));
			if (map[j][i] == 'E')
				exit++;
			if (map[j][i] == 'P')
				start_point++;
			if (map[j][i] == 'C')
				collect = 1;
			i++;
		}
		//para na próxima iteração apresentar mensagem de erro se as linhas não forem do mesmo tamanho
		prev_size = curr_size;
	}
	//se não existir nenhum E, P ou C ou se existirem mais do que um E e um P
	if ((exit == 0 || start_point == 0 || collect == 0) || (exit > 1 || start_point > 1))
			return (write(2, "Error./nInvalid map.", 19));
}

int main(int ac, char **av)
{
	char *ext;
	int fd;
	int curr_size;
	int prev_size;
	int exit;
	int start_point;
	int collect;

	curr_size = 0;
	prev_size = 0;
	exit = 0;
	start_point = 0;
	collect = 0;
	if (ac != 2)
		return (write(2, "Error./nMissing map.", 19));
	ext = ft_strrchr(av[1], '.');
	if (ext[1] != 'b' || ext[2] != 'e' || ext[3] != 'r' || ext[4])
		return (write(2, "Error./nWrong file. Must be .ber.", 32));
	fd = open(av[1], O_RDONLY);
	if (fd == - 1)
		return (write(2, "Error./nCan't read map.", 22));
	
}
