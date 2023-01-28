# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 16:05:35 by yettabaa          #+#    #+#              #
#    Updated: 2023/01/28 03:09:02 by yettabaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC

CFLAGS = -Wall -Wextra -Werror 

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -Ofast

MANDA = fdf.c fdf_parsing.c fdf_dda.c fdf_transformations3D.c

OMANDA = $(MANDA:.c=.o)

BONUS = fdf_bonus.c fdf_parsing.c fdf_hook_bonus.c fdf_dda.c fdf_transformations3D.c

OBONUS = $(BONUS:.c=.o)

LIBFT = libft_fdf/libft.a

NAME = fdf

all:	$(NAME)

%.o : %.c fdf.h
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OMANDA)
		make -C libft_fdf
		$(CC) $(MLXFLAGS) $(OMANDA) $(LIBFT)  -o $(NAME)
		
bonus:	$(OBONUS)
		make -C libft_fdf
		$(CC) $(MLXFLAGS) $(OBONUS) $(LIBFT)  -o $(NAME)

clean:
		make clean -C libft_fdf
		rm -f $(OMANDA) $(OBONUS)

fclean: clean
		rm -f $(NAME) $(LIBFT)
		
re: fclean all		
		