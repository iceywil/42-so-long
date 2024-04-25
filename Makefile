# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 18:40:46 by wscherre          #+#    #+#              #
#    Updated: 2024/02/20 19:23:34 by wscherre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc

FLAG		=	-Wall -Wextra -Werror -MMD

LIBFT_PATH	=	libft

LIBFT_FILE	=	libft.a

MLX_FILE	=	libmlx.a

LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

MLX_FLAGS	=	-lX11 -lXext

MLX_PATH	=	./minilibx-linux

MLX_LIB		=	$(MLX_PATH)/$(MLX_FILE)

MLX_EX		=	$(MLX_LIB) $(MLX_FLAGS)

SRCS		=	srcs/main.c \
				srcs/free.c \
				srcs/check_inputs.c \
				srcs/check_map.c \
				srcs/flood_fill.c \
				srcs/mlx_win.c \
				srcs/moves.c \
				srcs/show_map.c \

OBJS		=	$(SRCS:.c=.o)

DEPS 		= 	$(SRCS:.c=.d)

all: $(NAME)

-include $(DEPS)

%.o : %.c
	$(CC) $(FLAG) -c -o $@ $<

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

$(MLX_LIB): 
	make -C $(MLX_PATH)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(FLAG) $(OBJS) $(LIBFT_LIB) $(MLX_EX) -o $(NAME) -lm 

clean:
	make clean -sC $(MLX_PATH)
	make clean -sC $(LIBFT_PATH)
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
