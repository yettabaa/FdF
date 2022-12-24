/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:39 by yettabaa          #+#    #+#             */
/*   Updated: 2022/12/24 21:44:25 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft_fdf/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct fdf
{
	void	*mlx;
	void	*imgs;
	void	*mlx_win;
	int		x;
	int		y;
}			t_fdf;

void	ft_error(const char *str);
void	draw_point(void *mlx, void **imgs, void *mlx_win, int color, int x, int y);
void	window_mlx(t_fdf *pxl);
void 	get_z_coordinates(char *name, int ***tab_z, int ***tab_color,int *x, int *y);
void	cheker_z(char *str, int *tab_z, int *tab_color);
void	free_tab(int **tab, int y);
void	free_strs(char **strs);





void print_strs(char **s);
#endif