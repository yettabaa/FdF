/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:52:00 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/30 22:17:13 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_changes(t_colect *v)
{
	put_info(v);
	mlx_destroy_image(v->mlx.init, v->mlx.img);
	v->mlx.img = mlx_new_image(v->mlx.init, 1920, 1080);
	v->mlx.adr = mlx_get_data_addr(v->mlx.img, &v->mlx.bit_pxl, &v->mlx.line,
			&v->mlx.end);
	drawing_bonus(v);
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
		initialisation_bonus(v, 0, 90, 0);
	else if (keycode == 35)
		initialisation_bonus(v, 0, 0, 0);
	else if (keycode == 4)
		initialisation_bonus(v, 90, 0, 0);
	return (key_next(keycode, v), put_changes(v), 0);
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
	else if (keycode == 7)
		v->option_color = 0;
	put_changes(v);
	return (0);
}

int	mouse(int keycode, int x, int y, t_colect *v)
{
	if (keycode == 1)
	{
		v->trans_x = x - 250;
		v->trans_y = y;
	}	
	else if (keycode == 2)
		initialisation_bonus(v, 45, 45, -35);
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
