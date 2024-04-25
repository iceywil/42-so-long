/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:08:12 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/19 11:11:54 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define INTMAX 2147483647
# define INTMIN -2147483648

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

# define HEIGHT 32
# define WIDTH 32

# define WALL '1'
# define WATER '0'
# define ITEM 'C'
# define PLAYER 'P'
# define EXIT 'E'

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_Q 113
# define KEY_ESC 65307

# define PLAYER_X "assets/player.xpm"
# define HOLE_X "assets/hole.xpm"
# define ITEM_X "assets/item.xpm"
# define WALL_X "assets/wall.xpm"
# define WATER_X "assets/water.xpm"

typedef struct s_main
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		line_len;
	int		col_len;
	int		start_i;
	int		start_j;
	int		current_i;
	int		current_j;
	int		item_nbr;
	int		item_found;
	int		exit_found;
	void	*player;
	void	*hole;
	void	*item;
	void	*wall;
	void	*water;
	int		height;
	int		width;
	int		total_moves;
}			t_main;

// PARSING
void		store_map(t_main *so_long, char **argv);
void		check_inputs(t_main *so_long);
void		check_argv(t_main *so_long, char **argv);
void		check_map_rectangle(t_main *so_long);
void		check_map_exit(t_main *so_long);
void		check_map_item(t_main *so_long);
void		check_map_start(t_main *so_long);
void		check_map_closed(t_main *so_long);
void		check_map_valid(t_main *so_long, char **map_cpy, int i, int y);

// MLX
void		win_init(t_main *so_long);
void		load_imgs(t_main *so_long);
void		win_show_map(t_main *so_long);
int			handle_moves(t_main *so_long, int key, int i, int j);
void		print_img(t_main *so_long, void *img_ptr, int i, int j);
int			move_there(t_main *so_long, int i, int j);

// MLX UTILS
int			handle_keypress(int keysym, t_main *so_long);
int			handle_close(t_main *so_long);
void		mlx_destroy_imgs(t_main *so_long);

// FREE
void		free_all(t_main *so_long);
void		free_all_and_error(t_main *so_long, char *error);
void		malloc_exit(t_main *so_long);
void		mlx_exit(t_main *so_long);

#endif