/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:52:00 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/28 20:00:59 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key(int keycode,t_colect *v)
{
	if (keycode == 53)
		exit(0);
///	protection	
	else if (keycode == 69 && v->scaling_z < 1337)
		v->scaling_z += 1;
	else if (keycode == 78 && v->scaling_z < 1337)
		v->scaling_z -= 1;
	else if (keycode == 91)
		v->angle_x += 5;
	else if (keycode == 84)
		v->angle_x -= 5;
	else if (keycode == 86)
		v->angle_y += 5;
	else if (keycode == 88)
		v->angle_y -= 5;
	else if (keycode == 89)
		v->angle_z += 5;
	else if (keycode == 92)
		v->angle_z -= 5;
	else if (keycode == 123)
		v->trans_x -= 30;
	else if (keycode == 124)
		v->trans_x += 30;
	else if (keycode == 126)
		v->trans_y -= 30;
	else if (keycode == 125)
		v->trans_y += 30;
	else if (keycode == 35)
	{
		transformations_parameter(v);
		v->angle_x = 0;
		v->angle_y = 0;
		v->angle_z = 0;
	}	
	else if (keycode == 15)
		transformations_parameter(v);
	printf("ang_x = %d, ang_y = %d, ang_z = %d z = %d\n", v->angle_x, v->angle_y, v->angle_z, v->scaling_z);//!!!!
	mlx_destroy_image(v->mlx.init, v->mlx.img);
	v->mlx.img = mlx_new_image(v->mlx.init, 1920, 1080);
	v->mlx.addr = mlx_get_data_addr(v->mlx.img, &v->mlx.bits_per_pixel, &v->mlx.line_length,
			&v->mlx.endian);
	drawing(v);
	mlx_put_image_to_window(v->mlx.init, v->mlx.win, v->mlx.img, 0, 0);
	return (0);
}

int	mouse(int keycode, int x, int y, t_colect *v)
{
	x = y;
	if (keycode == 4 && v->scaling_x > 1)
	{
		v->scaling_x -= 1;
		v->scaling_y -= 1;
	}
	else if (keycode == 5 && v->scaling_x < 1337)
	{
		v->scaling_x += 1;
		v->scaling_y += 1;
	}
	printf("zoomx = %d, zoomy = %d\n", v->scaling_x, v->scaling_y); // !!!!!!!!
	mlx_destroy_image(v->mlx.init, v->mlx.img);
	v->mlx.img = mlx_new_image(v->mlx.init, 1920, 1080);
	v->mlx.addr = mlx_get_data_addr(v->mlx.img, &v->mlx.bits_per_pixel, &v->mlx.line_length,
			&v->mlx.endian);
	drawing(v);
	mlx_put_image_to_window(v->mlx.init, v->mlx.win, v->mlx.img, 0, 0);
	return (0);
}