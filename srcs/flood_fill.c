/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:17:39 by wscherre          #+#    #+#             */
/*   Updated: 2024/04/25 16:44:26 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_valid(t_main *so_long, char **map_cpy, int i, int j)
{
	if (map_cpy[i][j] == '1')
		return ;
	if (map_cpy[i][j] == 'E')
	{
		so_long->exit_found = 1;
		return ;
	}
	if (map_cpy[i][j] == 'C')
		so_long->item_found++;
	map_cpy[i][j] = '1';
	if (so_long->map[i][j + 1] != '1')
		check_map_valid(so_long, map_cpy, i, j + 1);
	if (so_long->map[i][j - 1] != '1')
		check_map_valid(so_long, map_cpy, i, j - 1);
	if (map_cpy[i + 1][j] != '1')
		check_map_valid(so_long, map_cpy, i + 1, j);
	if (map_cpy[i - 1][j] != '1')
		check_map_valid(so_long, map_cpy, i - 1, j);
}
