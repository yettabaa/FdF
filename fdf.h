/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:39 by yettabaa          #+#    #+#             */
/*   Updated: 2022/12/23 03:46:07 by yettabaa         ###   ########.fr       */
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
void	get_x_y(char *name, int *x, int *y);
void	draw_point(void *mlx, void **imgs, void *mlx_win, int color, int x, int y);
void	window_mlx(t_fdf *pxl);
char	**gnl_maps_xy(char *name, int *x, int *y);
int		**get_z_coordinates(char **maps, int x, int y);
int     cheker_z(char *str);
int		**get_colors(char **maps, int x, int y);
int     cheker_colors(char *str);
int		count_x(char const *s);
void	free_tab(int **tab, int y);
void	free_strs(char **strs);
#endif