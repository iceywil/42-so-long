/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:50:20 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/19 15:12:35 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	store_map(t_main *so_long, char **argv)
{
	char	*str;
	char	*lines;
	char	*buff;
	int		fd;

	(check_argv(so_long, argv), fd = open(argv[1], O_RDONLY));
	str = ft_get_next_line(fd);
	buff = NULL;
	lines = NULL;
	while (str)
	{
		buff = lines;
		lines = ft_strjoin(buff, str);
		if (!lines)
			(free(str), malloc_exit(so_long));
		if (buff)
			free(buff);
		(free(str), str = ft_get_next_line(fd));
	}
	so_long->map = ft_split(lines, '\n');
	free(lines);
	if (!so_long->map || !so_long->map[0])
		malloc_exit(so_long);
	so_long->col_len = ft_tab_len(so_long->map);
	so_long->line_len = ft_strlen((so_long->map)[0]);
}

void	check_argv(t_main *so_long, char **argv)
{
	int		fd;
	char	buff[1];
	int		i;

	i = 0;
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e' || argv[1][i - 3] != 'b'
		|| argv[1][i - 4] != '.')
		free_all_and_error(so_long, "Error\nFile is not type .ber");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		free_all_and_error(so_long, "Error\nFD Error");
	if (read(fd, buff, sizeof(buff)) == -1)
		free_all_and_error(so_long, "Error\nFile is a Directory");
	close(fd);
}

void	check_inputs(t_main *so_long)
{
	char	**map_cpy;
	int		i;

	i = 0;
	(check_map_exit(so_long), check_map_item(so_long));
	(check_map_start(so_long), check_map_rectangle(so_long));
	(check_map_closed(so_long), so_long->item_found = 0);
	map_cpy = malloc(sizeof(char *) * (so_long->col_len + 1));
	if (!map_cpy)
		malloc_exit(so_long);
	map_cpy[so_long->col_len] = NULL;
	while (so_long->map[i])
	{
		map_cpy[i] = ft_strdup(so_long->map[i]);
		if (!map_cpy[i])
			(ft_free_double_tab(&map_cpy), malloc_exit(so_long));
		i++;
	}
	check_map_valid(so_long, map_cpy, so_long->start_i, so_long->start_j);
	ft_free_double_tab(&map_cpy);
	if (so_long->item_found != so_long->item_nbr)
		free_all_and_error(so_long,
			"Error\nMap doesn't have a path to all collectibles");
	if (so_long->exit_found != 1)
		free_all_and_error(so_long, "Error\nMap doesn't have a path to exit");
}
