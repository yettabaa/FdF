# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 16:05:35 by yettabaa          #+#    #+#              #
#    Updated: 2023/02/03 01:34:28 by yettabaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -fsanitize=address -g

MLX_DIR = mlx-linux

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -Ofast

MLX_LINUX = -L$(MLX_DIR) -lmlx -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -Ofast

MANDA = fdf.c fdf_parsing.c fdf_dda.c fdf_hook.c fdf_transformations3D.c fdf_gradient_colors.c fdf_infos.c

OMANDA = $(MANDA:.c=.o)

LIBFT = libft_fdf/libft.a

NAME = fdf

all:	$(NAME)

%.o : %.c fdf.h
		$(CC) $(CFLAGS) -I/usr/include -I$(MLX_DIR) -O3 -c $< -o $@

$(NAME):	$(OMANDA)
		make -C libft_fdf
		make -C mlx-linux
		$(CC) $(CFLAGS) $(OMANDA) $(LIBFT) $(MLX_LINUX) -o $(NAME)
		
clean:
		make clean -C libft_fdf
		make clean -C mlx-linux
		rm -f $(OMANDA) $(OBONUS)

fclean: clean
		rm -f $(NAME) $(LIBFT)
		
re: fclean all		
		