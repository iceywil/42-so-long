/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:47:55 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/16 19:44:50 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_moves(t_main *so_long, int key, int i, int j)
{
	if ((key == KEY_RIGHT || key == KEY_D) && (move_there(so_long, i,
				++j)) == 1)
		return (print_img(so_long, so_long->water, i, --j), 1);
	else if ((key == KEY_LEFT || key == KEY_A) && (move_there(so_long, i,
				--j)) == 1)
		return (print_img(so_long, so_long->water, i, ++j), 1);
	else if ((key == KEY_DOWN || key == KEY_S) && (move_there(so_long, ++i,
				j)) == 1)
		return (print_img(so_long, so_long->water, --i, j), 1);
	else if ((key == KEY_UP || key == KEY_W) && (move_there(so_long, --i,
				j)) == 1)
		return (print_img(so_long, so_long->water, ++i, j), 1);
	else
		return (0);
	return (0);
}

int	move_there(t_main *so_long, int i, int j)
{
	if (so_long->map[i][j] == '1')
		return (0);
	if (so_long->map[i][j] == 'E' && so_long->item_found != so_long->item_nbr)
		return (0);
	else if (so_long->map[i][j] == 'C')
	{
		so_long->item_found++;
		so_long->map[i][j] = '0';
	}
	else if (so_long->map[i][j] == 'E'
		&& so_long->item_found == so_long->item_nbr)
		(free_all(so_long), exit(0));
	print_img(so_long, so_long->player, i, j);
	so_long->current_i = i;
	so_long->current_j = j;
	return (1);
}
