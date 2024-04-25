/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:47:55 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/16 22:21:31 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_imgs(t_main *so_long)
{
	so_long->width = 32;
	so_long->height = 32;
	so_long->player = mlx_xpm_file_to_image(so_long->mlx_ptr, PLAYER_X,
			&so_long->width, &so_long->height);
	so_long->hole = mlx_xpm_file_to_image(so_long->mlx_ptr, HOLE_X,
			&so_long->width, &so_long->height);
	so_long->item = mlx_xpm_file_to_image(so_long->mlx_ptr, ITEM_X,
			&so_long->width, &so_long->height);
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx_ptr, WALL_X,
			&so_long->width, &so_long->height);
	so_long->water = mlx_xpm_file_to_image(so_long->mlx_ptr, WATER_X,
			&so_long->width, &so_long->height);
	if (!so_long->player || !so_long->hole || !so_long->item || !so_long->wall
		|| !so_long->water)
		free_all_and_error(so_long, "Error\nMLX XPM to Img Error\n");
}

void	win_show_map(t_main *so_long)
{
	int	i;
	int	j;

	i = 0;
	load_imgs(so_long);
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == WALL)
				(print_img(so_long, so_long->water, i, j), print_img(so_long,
						so_long->wall, i, j));
			else if (so_long->map[i][j] == WATER)
				print_img(so_long, so_long->water, i, j);
			else if (so_long->map[i][j] == ITEM)
				print_img(so_long, so_long->item, i, j);
			else if (so_long->map[i][j] == PLAYER)
				print_img(so_long, so_long->player, i, j);
			else if (so_long->map[i][j] == EXIT)
				print_img(so_long, so_long->hole, i, j);
			j++;
		}
		i++;
	}
}

void	print_img(t_main *so_long, void *img_ptr, int i, int j)
{
	int	pos_i;
	int	pos_j;

	pos_i = j * 32;
	pos_j = i * 32;
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, img_ptr, pos_i,
		pos_j);
}
