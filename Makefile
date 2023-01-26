# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 16:05:35 by yettabaa          #+#    #+#              #
#    Updated: 2023/01/26 02:37:41 by yettabaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC

# CFLAGS = -Wall -Wextra -Werror 

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -Ofast

MANDA = fdf.c fdf_parsing.c fdf_mlx.c fdf_dda.c fdf_transformations3D.c

OMANDA = $(MANDA:.c=.o)

LIBFT = libft_fdf/libft.a

NAME = fdf

all:	$(NAME)

%.o : %.c fdf.h
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OMANDA)
		make -C libft_fdf
		$(CC) $(MLXFLAGS) $(OMANDA) $(LIBFT)  -o $(NAME)

clean:
		make clean -C libft_fdf
		rm -f $(OMANDA)

fclean: clean
		rm -f $(NAME) $(LIBFT)
		
re: fclean all		
		