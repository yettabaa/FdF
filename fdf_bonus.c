/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:42 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/30 22:32:42 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialisation_bonus(t_colect *v, int ang_x, int ang_y, int ang_z)
{
	if (v->width > 100)
	{
		v->scaling_x = (1500 / v->width);
		v->scaling_y = (1500 / v->width);
		v->scaling_z = 2;
	}
	else
	{
		v->scaling_x = (1080 / v->width) * 0.8;
		v->scaling_y = (1080 / v->width) * 0.8;
		v->scaling_z = 3;
	}
	v->angle_x = ang_x;
	v->angle_y = ang_y;
	v->angle_z = ang_z;
	v->trans_x = 1920 / 2;
	v->trans_y = 1080 / 2;
	v->option_color = 0;
	put_info(v);
}

void	transformations_bonus(t_colect *v, int next_i, int next_j)
{
	scaling(v, next_i, next_j);
	rotation(v, &v->x, &v->y, v->tab_z[v->j][v->i]);
	rotation(v, &v->x1, &v->y1, v->tab_z[next_j][next_i]);
	translation(v, &v->x, &v->y);
	translation(v, &v->x1, &v->y1);
}

static int	destroy_bonus(void)
{
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_colect	v;

	if (ac != 2)
		ft_error("Invalid number of arguments.\n");
	v.mlx.init = mlx_init();
	v.mlx.win = mlx_new_window(v.mlx.init, 2170, 1080, "FdF");
	get_data(&v, av);
	initialisation_bonus(&v, 45, 45, -35);
	v.mlx.img = mlx_new_image(v.mlx.init, 1920, 1080);
	v.mlx.adr = mlx_get_data_addr(v.mlx.img, &v.mlx.bit_pxl, &v.mlx.line,
			&v.mlx.end);
	printf("x = %d, y = %d\n", v.width, v.hiegth);
	drawing_bonus(&v);
	mlx_put_image_to_window(v.mlx.init, v.mlx.win, v.mlx.img, 250, 0);
	mlx_mouse_hook(v.mlx.win, mouse, &v);
	mlx_hook(v.mlx.win, 2, 0, key, &v);
	mlx_hook(v.mlx.win, 17, 0, destroy_bonus, &v);
	mlx_loop(v.mlx.init);
}
