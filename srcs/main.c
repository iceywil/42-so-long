/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:40:35 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/19 17:40:58 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_main	so_long;

	if (argc == 2)
	{
		so_long.mlx_ptr = NULL;
		so_long.win_ptr = NULL;
		so_long.map = NULL;
		so_long.player = NULL;
		so_long.hole = NULL;
		so_long.item = NULL;
		so_long.wall = NULL;
		so_long.water = NULL;
		so_long.exit_found = 0;
		so_long.total_moves = 0;
		store_map(&so_long, argv);
		check_inputs(&so_long);
		so_long.item_found = 0;
		win_init(&so_long);
		(free_all(&so_long), exit(0));
	}
	ft_putendl_fd("Error\nRequire exactly 1 arg", 2);
	return (0);
}

void	win_init(t_main *so_long)
{
	so_long->mlx_ptr = mlx_init();
	if (so_long->mlx_ptr == NULL)
		mlx_exit(so_long);
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, 1920, 1080,
			"Soooooo Loooonnnnnggg");
	if (so_long->win_ptr == NULL)
		mlx_exit(so_long);
	so_long->current_i = so_long->start_i;
	so_long->current_j = so_long->start_j;
	win_show_map(so_long);
	mlx_hook(so_long->win_ptr, KeyPress, KeyPressMask, &handle_keypress,
		so_long);
	mlx_hook(so_long->win_ptr, DestroyNotify, KeyPressMask, &handle_close,
		so_long);
	mlx_loop(so_long->mlx_ptr);
	mlx_destroy_display(so_long->mlx_ptr);
}

int	handle_close(t_main *so_long)
{
	free_all(so_long);
	exit(0);
	return (0);
}
