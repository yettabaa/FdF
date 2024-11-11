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
	v->mlx.img = mlx_new_image(v->mlx.init, RENDER_WIDTH, HIEGTH);
	v->mlx.adr = mlx_get_data_addr(v->mlx.img, &v->mlx.bit_pxl, &v->mlx.line,
			&v->mlx.end);
	drawing_bonus(v);
	mlx_put_image_to_window(v->mlx.init, v->mlx.win, v->mlx.img, INFO_WIDTH, 0);
}

int	key(int keycode, t_colect *v)
{
	if (keycode == KEY_ECHAP)
		exit(0);
	else if (keycode == KEY_PLUS && v->scaling_z < 1337)
		v->scaling_z += 1;
	else if (keycode == KEY_MINUS && v->scaling_z > -1337)
		v->scaling_z -= 1;
	else if (keycode == KEY_2)
		v->angle_x += 5;
	else if (keycode == KEY_8)
		v->angle_x -= 5;
	else if (keycode == KEY_4)
		v->angle_y += 5;
	else if (keycode == KEY_6)
		v->angle_y -= 5;
	else if (keycode == KEY_7)
		v->angle_z -= 5;
	else if (keycode == KEY_9)
		v->angle_z += 5;
	else if (keycode == KEY_H)
		initialisation_bonus(v, 0, 90, 0);
	else if (keycode == KEY_P)
		initialisation_bonus(v, 0, 0, 0);
	else if (keycode == KEY_V)
		initialisation_bonus(v, 90, 0, 0);
	else if (keycode == KEY_RIGHT)
		v->trans_x += 30;
	else if (keycode == KEY_LEFT)
		v->trans_x -= 30;
	else if (keycode == KEY_DOWN)
		v->trans_y -= 30;
	else if (keycode == KEY_UP)
		v->trans_y += 30;
	else if (keycode == KEY_X)
		v->option_color = 1337;
	else if (keycode == KEY_C)
		v->option_color = 0;
	return (0);
}

int	mouse(int keycode, int x, int y, t_colect *v)
{
	if (keycode == 1)
	{
		v->trans_x = x - INFO_WIDTH;
		v->trans_y = y;
	}	
	else if (keycode == 3)
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
	return (0);
}
