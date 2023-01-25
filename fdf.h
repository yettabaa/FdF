/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:39 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/25 00:38:58 by yettabaa         ###   ########.fr       */
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

typedef struct s_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx;

typedef struct s_data
{
    int x;
    int y;
    int **tab_z;
	int **tab_c;
}			t_data;

typedef struct s_get_data
{
	int		i;
	int		j;
	int		save_x;
	int		**tabz;
	int		**tabc;
	char	**strs;
	char	**maps;
}	t_get_data;


void	ft_error(const char *str);
void	dda(t_mlx img, int color, double x, double y, double x1, double y1);
void rotation(int *x, int *y, int z);
double to_degrees(double radians);
double to_radians(double degree);
int 	**get_data(char **maps, int ***tab_color,int *x, int *y);
void	cheker_z(char *str, int *tab_z, int *tab_color);
void	free_tab(int **tab, int y);
void	free_strs(char **strs);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);




void print_strs(char **s);
#endif