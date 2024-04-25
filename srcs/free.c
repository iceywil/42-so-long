/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:50:46 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/16 20:20:30 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_all(t_main *so_long)
{
	if (so_long)
	{
		if (so_long->map)
			ft_free_double_tab(&so_long->map);
		if (so_long)
			mlx_destroy_imgs(so_long);
		if (so_long->mlx_ptr && so_long->win_ptr)
			mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
		if (so_long->mlx_ptr)
			mlx_destroy_display(so_long->mlx_ptr);
		free(so_long->mlx_ptr);
	}
}

void	free_all_and_error(t_main *so_long, char *error)
{
	free_all(so_long);
	ft_putendl_fd(error, 2);
	exit(1);
}

void	malloc_exit(t_main *so_long)
{
	free_all(so_long);
	ft_putendl_fd("Error\nMalloc Error", 2);
	exit(1);
}

void	mlx_exit(t_main *so_long)
{
	if (so_long)
		free_all(so_long);
	ft_putendl_fd("Error\nMLX Error", 2);
	exit(1);
}

void	mlx_destroy_imgs(t_main *so_long)
{
	if (so_long->mlx_ptr)
	{
		if (so_long->player)
			(mlx_destroy_image(so_long->mlx_ptr, so_long->player),
				so_long->player = NULL);
		if (so_long->hole)
			(mlx_destroy_image(so_long->mlx_ptr, so_long->hole),
				so_long->hole = NULL);
		if (so_long->item)
			(mlx_destroy_image(so_long->mlx_ptr, so_long->item),
				so_long->item = NULL);
		if (so_long->wall)
			(mlx_destroy_image(so_long->mlx_ptr, so_long->wall),
				so_long->wall = NULL);
		if (so_long->water)
			(mlx_destroy_image(so_long->mlx_ptr, so_long->water),
				so_long->water = NULL);
	}
}
