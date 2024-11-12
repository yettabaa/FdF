/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:42 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/31 04:55:59 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialisation_bonus(t_colect *v, int ang_x, int ang_y, int ang_z)
{
	if (v->width > 100)
	{
		v->scaling_x = (1200 / v->width);
		v->scaling_y = (1200 / v->width);
		v->scaling_z = 2;
	}
	else
	{
		v->scaling_x = (HIEGTH / v->width) * 0.8;
		v->scaling_y = (HIEGTH / v->width) * 0.8;
		v->scaling_z = 3;
	}
	v->angle_x = ang_x;
	v->angle_y = ang_y;
	v->angle_z = ang_z;
	v->trans_x = RENDER_WIDTH / 2;
	v->trans_y = HIEGTH / 2;
	v->option_color = 0;
}

void	transformations_bonus(t_colect *v, int next_i, int next_j)
{
	scaling(v, next_i, next_j);
	rotation(v, &v->x, &v->y, v->tab_z[v->j][v->i]);
	rotation(v, &v->x1, &v->y1, v->tab_z[next_j][next_i]);
	translation(v, &v->x, &v->y);
	translation(v, &v->x1, &v->y1);
}

static int	destroy_bonus(t_colect *v)
{
	int j = 0;
	while (j < v->hiegth)
	{
		free(v->tab_z[j]);
		free(v->tab_c[j]);
		j++;
	}
	free(v->tab_z);
	free(v->tab_c);
	exit(0);
	return (0);
}

int loop_hook(void *ptr)
{
    t_colect *v;
    
    v = ptr;
	v->mlx.img = mlx_new_image(v->mlx.init, RENDER_WIDTH, HIEGTH);
	v->mlx.adr = mlx_get_data_addr(v->mlx.img, &v->mlx.bit_pxl, &v->mlx.line,
			&v->mlx.end);
	drawing_bonus(v);
	put_info(v);
	mlx_put_image_to_window(v->mlx.init, v->mlx.win, v->mlx.img, INFO_WIDTH, 0);
    mlx_destroy_image(v->mlx.init, v->mlx.img);
    return (0);
}

int	main(int ac, char **av)
{
	t_colect	v;

	if (ac != 2)
		ft_error("Invalid number of arguments.\n");
	v.mlx.init = mlx_init();
	v.mlx.win = mlx_new_window(v.mlx.init, WIDTH, HIEGTH, "FdF");
	get_data(&v, av);
	if (!v.width || !v.hiegth)
		ft_error("Empty map.\n");
	initialisation_bonus(&v, 45, 45, -35);
	mlx_loop_hook(v.mlx.init, loop_hook, &v);
	mlx_mouse_hook(v.mlx.win, mouse, &v);
	mlx_hook(v.mlx.win, 2, 1L<<0, key, &v);
	mlx_hook(v.mlx.win, 17, 0, destroy_bonus, &v);
	mlx_loop(v.mlx.init);
	return (0);
}
