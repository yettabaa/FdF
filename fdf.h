/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:39 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/26 03:30:27 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft_fdf/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx;

typedef struct s_get_data
{
	int		i;
	int		j;
	int		save_x;
	char	**strs;
	char	**maps;
}			t_get_data;

typedef struct s_colect
{
	int		hiegth;
	int		width;
	int		**tab_z;
	int		**tab_c;
	int scaling_x;
	int scaling_y;
	int scaling_z;
	int trans_x;
	int trans_y;
	int		i;
	int		j;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	double	x;
	double	x1;
	double	y;
	double	y1;
}			t_colect;

void		get_data(t_colect *v, char **av);
void		dda(t_mlx img, t_colect v);
void		transformations(t_colect *v, int next_i, int next_j);
void scaling(t_colect *v, int next_i, int next_j);
void	rotation(t_colect *v, double *x, double *y, double z);
void translation(t_colect *v, double *x, double *y);
void		ft_error(const char *str);
double		to_radians(double degree);
void		cheker_z(char *str, int *tab_z, int *tab_color);
void		free_tab(int **tab, int y);
void		free_strs(char **strs);
void		my_mlx_pixel_put(t_mlx *data, int x, int y, int color);


#endif