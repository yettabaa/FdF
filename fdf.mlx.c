/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:52:00 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/21 20:13:59 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void	draw_point(void *mlx, void **imgs, void *mlx_win,int color, int x, int y)
// {
// 	t_data img;
// 	// void    *mlx_win;
// 	// mlx_win = mlx_new_window(mlx, 540, 540, "Hello world!");
// 	// img.addr = mlx_get_data_addr(*imgs, &img.bits_per_pixel, &img.line_length,
// 	// 		&img.endian);
// 	// // puts("ss");
// 	// mlx_put_image_to_window(mlx, mlx_win, *imgs, 0, 0);
// 	my_mlx_pixel_put(&img, x, y, color);
// }