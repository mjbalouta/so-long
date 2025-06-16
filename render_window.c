/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:30:26 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/06/16 15:11:24 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_window_map(t_window *window)
{
	window->img = mlx_xpm_file_to_image(window->mlx_connection, );
}

void	render_window(void)
{
	t_window	window;

	window.mlx_connection = mlx_init();
	if (!window.mlx_connection)
		return ;
	window.mlx_window = mlx_new_window(window.mlx_connection, 1920, 1080, "so_long");
	if (!window.mlx_window)
	{
		mlx_destroy_display(window.mlx_connection);
		free(window.mlx_connection);
		return ;
	}
	fill_window_map(&window);
	mlx_loop(window.mlx_connection);
	mlx_destroy_display(window.mlx_connection);
	free(window.mlx_connection);
}