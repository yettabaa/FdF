/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:39 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/31 05:41:00 by yettabaa         ###   ########.fr       */
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

typedef struct s_get_data
{
	int		i;
	int		j;
	int		save_x;
	char	**strs;
	char	**maps;
}			t_get_data;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	char	*adr;
	int		bit_pxl;
	int		line;
	int		end;
}			t_mlx;

typedef struct s_colect
{
	int		hiegth;
	int		width;
	int		**tab_z;
	int		**tab_c;
	int		i;
	int		j;
	int		scaling_x;
	int		scaling_y;
	int		scaling_z;
	int		angle_x;
	int		angle_y;
	int		angle_z;
	int		trans_x;
	int		trans_y;
	int		color;
	int		option_color;
	double	x;
	double	x1;
	double	y;
	double	y1;
	t_mlx	mlx;
}			t_colect;

void		get_data(t_colect *v, char **av);
void		ft_error(const char *str);
void		my_mlx_pixel_put(t_colect *v, int x, int y, int color);
void		drawing(t_colect *v);
void		drawing_bonus(t_colect *v);
void		initialisation_bonus(t_colect *v, int ang_x, int ang_y, int ang_z);
void		transformations_bonus(t_colect *v, int next_i, int next_j);
void		transformations(t_colect *v, int next_i, int next_j);
void		isometric(t_colect *v, double *x, double *y, double z);
void		scaling(t_colect *v, int next_i, int next_j);
void		rotation(t_colect *v, double *x, double *y, double z);
void		translation(t_colect *v, double *x, double *y);
double		rad(double degree);
int			ft_gradient(int start, int end, double percent);
int			mouse(int keycode, int x, int y, t_colect *v);
int			key(int keycode, t_colect *v);
int			key_next(int keycode, t_colect *v);
void		put_info(t_colect *v);
void		my_mlx_pixel_put(t_colect *v, int x, int y, int color);
#endif