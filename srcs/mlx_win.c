/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:47:55 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/19 11:15:09 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_keypress(int keysym, t_main *so_long)
{
	int	key;

	key = keysym;
	if (key == KEY_ESC)
		(free_all(so_long), exit(0));
	else
	{
		if (handle_moves(so_long, key, so_long->current_i, so_long->current_j))
		{
			so_long->total_moves++;
			ft_printf("Total Count of Moves: %d\n", so_long->total_moves);
		}
	}
	return (0);
}
