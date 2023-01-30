/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:52:00 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/30 05:37:36 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void put_info(t_colect *v)
{
	void *image;
	int x;
	int y;
	char *z;
	char *rx;
	char *ry;
	char *rz;
	char *zoom;
	image = mlx_new_image(v->mlx.init, 250, 1080);
	v->mlx.adr = mlx_get_data_addr(image, &v->mlx.bit_pxl, &v->mlx.line,
		&v->mlx.end);
	y = -1;
	while (++y < 1080)
	{
		x = -1;
		while (++x < 250)
			my_mlx_pixel_put(v, x, y, 0x060a24);
	}
	mlx_put_image_to_window(v->mlx.init, v->mlx.win, image, 0, 0);
	z =  ft_strjoin("Z = ", ft_itoa(v->scaling_z));
	mlx_string_put(v->mlx.init, v->mlx.win, 15 , 10, 16777215 , z);
	zoom = ft_strjoin("Zoom = ", ft_itoa(v->scaling_x));
	mlx_string_put(v->mlx.init, v->mlx.win, 15 , 35, 16777215 , zoom);
	rx = ft_strjoin("Rotations(X)° = ", ft_itoa(v->angle_x));
	mlx_string_put(v->mlx.init, v->mlx.win, 15 , 60, 16777215 , rx);
	ry = ft_strjoin("Rotations(Y)° = ", ft_itoa(v->angle_y));
	mlx_string_put(v->mlx.init, v->mlx.win, 15 , 85, 16777215 , ry);
	rz = ft_strjoin("Rotations(Z)° = ", ft_itoa(v->angle_z));
	mlx_string_put(v->mlx.init, v->mlx.win, 15 , 110, 16777215, rz);
	mlx_string_put(v->mlx.init, v->mlx.win, 15 , 650, 0xDAA520, "Altitude : +/-");
	mlx_string_put(v->mlx.init, v->mlx.win, 15 , 675, 0xDAA520, "Marvelous color : C");
	mlx_string_put(v->mlx.init, v->mlx.win, 15 , 700, 0xDAA520, "Zoom In / Out :");
	mlx_string_put(v->mlx.init, v->mlx.win, 45 , 725, 16777215, "Scroll mouse");
	mlx_string_put(v->mlx.init, v->mlx.win, 15 , 750, 0xDAA520, "Init view : Right click");
	mlx_string_put(v->mlx.init, v->mlx.win, 15 , 775, 0xDAA520, "Any place : Left click");
	mlx_string_put(v->mlx.init, v->mlx.win, 15 , 800, 0xDAA520, "Multi view :");
	mlx_string_put(v->mlx.init, v->mlx.win, 45 , 825, 16777215, "2D view : P");
	mlx_string_put(v->mlx.init, v->mlx.win, 45 , 850, 16777215, "Horizontal view : H");
	mlx_string_put(v->mlx.init, v->mlx.win, 45 , 875, 16777215, "Vertical view : V");
	mlx_string_put(v->mlx.init, v->mlx.win, 15 , 900, 0xDAA520, "Rotate :");
	mlx_string_put(v->mlx.init, v->mlx.win, 45 , 925, 16777215, "X-Axis : 2/8");
	mlx_string_put(v->mlx.init, v->mlx.win, 45 , 950, 16777215, "Y-Axis : 4/6");
	mlx_string_put(v->mlx.init, v->mlx.win, 45 , 975, 16777215, "Z-Axis : 7/9");
	mlx_string_put(v->mlx.init, v->mlx.win, 15 , 1000, 0xDAA520, "Translation :");
	mlx_string_put(v->mlx.init, v->mlx.win, 45 , 1025, 16777215, "keyboard arrow");
	free(z);
	free(rx);
	free(ry);
	free(rz);
	free(zoom);
}

void put_changes(t_colect *v)
{
	put_info(v);
	mlx_destroy_image(v->mlx.init, v->mlx.img);
	v->mlx.img = mlx_new_image(v->mlx.init, 1920, 1080);
	v->mlx.adr = mlx_get_data_addr(v->mlx.img, &v->mlx.bit_pxl, &v->mlx.line,
			&v->mlx.end);
	drawing(v);
	mlx_put_image_to_window(v->mlx.init, v->mlx.win, v->mlx.img, 250, 0);
}

int	key(int keycode, t_colect *v)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 69 && v->scaling_z < 1337)
		v->scaling_z += 1;
	else if (keycode == 78 && v->scaling_z > -1337)
		v->scaling_z -= 1;
	else if (keycode == 91)
		v->angle_x += 5;
	else if (keycode == 84)
		v->angle_x -= 5;
	else if (keycode == 86)
		v->angle_y += 5;
	else if (keycode == 88)
		v->angle_y -= 5;
	else if (keycode == 92)
		v->angle_z -= 5;
	else if (keycode == 9)
	{
		v->angle_x = 0;
		v->angle_y = 90;
		v->angle_z = 0;
	}	
	key_next(keycode, v);
	put_changes(v);
	return (0);
}

int	key_next(int keycode, t_colect *v)
{
	if (keycode == 89)
		v->angle_z += 5;
	else if (keycode == 123)
		v->trans_x -= 30;
	else if (keycode == 124)
		v->trans_x += 30;
	else if (keycode == 126)
		v->trans_y -= 30;
	else if (keycode == 125)
		v->trans_y += 30;
	else if (keycode == 8)
		v->option_color = 1337;
	else if (keycode == 35)
	{
		v->angle_x = 0;
		v->angle_y = 0;
		v->angle_z = 0;
	}
	else if (keycode == 4)
	{
		v->angle_x = 90;
		v->angle_y = 0;
		v->angle_z = 0;
	}
	put_changes(v);		
	return (0);
}

int	mouse(int keycode, int x, int y, t_colect *v)
{
	if (keycode == 1)
	{
		v->trans_x = x;
		v->trans_y = y;
	}	
	else if (keycode == 2)
		transformations_parameter_bonus(v);
	else if (keycode == 4 && v->scaling_x > 1)
	{
		v->scaling_x -= 1;
		v->scaling_y -= 1;
	}
	else if (keycode == 5 && v->scaling_x < 1337)
	{
		v->scaling_x += 1;
		v->scaling_y += 1;
	}
	put_changes(v);
	return (0);
}