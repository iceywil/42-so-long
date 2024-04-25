/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:50:08 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/16 20:34:28 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_exit(t_main *so_long)
{
	int	i;
	int	j;
	int	exit_flag;

	i = 0;
	exit_flag = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'E')
				exit_flag++;
			if (so_long->map[i][j] != 'E' && so_long->map[i][j] != '0'
				&& so_long->map[i][j] != '1' && so_long->map[i][j] != 'C'
				&& so_long->map[i][j] != 'P')
				free_all_and_error(so_long, "Error\nMap have wrong char");
			j++;
		}
		i++;
	}
	if (exit_flag != 1)
		free_all_and_error(so_long, "Error\nMap doesn't have exactly 1 exit");
}

void	check_map_item(t_main *so_long)
{
	int	i;
	int	j;
	int	item_flag;

	i = 0;
	item_flag = 0;
	so_long->item_nbr = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'C')
			{
				item_flag++;
				so_long->item_nbr++;
			}
			j++;
		}
		i++;
	}
	if (item_flag < 1)
		free_all_and_error(so_long, "Error\nMap doesn't have at least 1 item");
}

void	check_map_start(t_main *so_long)
{
	int	i;
	int	j;
	int	start_flag;

	i = 0;
	start_flag = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'P')
			{
				start_flag++;
				so_long->start_i = i;
				so_long->start_j = j;
			}
			j++;
		}
		i++;
	}
	if (start_flag != 1)
		free_all_and_error(so_long, "Error\nMap doesn't have exactly 1 start");
}

void	check_map_rectangle(t_main *so_long)
{
	int	i;
	int	first_len;
	int	comp_len;

	first_len = so_long->line_len;
	i = 0;
	while (so_long->map[i])
	{
		comp_len = ft_strlen(so_long->map[i]);
		if (first_len != comp_len)
			free_all_and_error(so_long, "Error\nMap is not a rectangle");
		i++;
	}
}

void	check_map_closed(t_main *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		if (i == 0 || i == so_long->col_len - 1)
		{
			while (so_long->map[i][j])
			{
				if (so_long->map[i][j++] != '1')
					free_all_and_error(so_long, "Error\nMap is not closed");
			}
		}
		else
		{
			if (so_long->map[i][0] != '1' || so_long->map[i][so_long->line_len
				- 1] != '1')
				free_all_and_error(so_long, "Error\nMap is not closed");
		}
		i++;
	}
}
