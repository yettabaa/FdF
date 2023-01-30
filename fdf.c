/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:29:05 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/29 20:50:05 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void transformations_parameter(t_colect *v)
{
	if (v->width > 100)
	{
		v->scaling_x = (1500 / v->width) ;
		v->scaling_y = (1500 / v->width) ;
		v->scaling_z = 2;
	}
	else
	{
		v->scaling_x = (1080 / v->width) * 0.8;
		v->scaling_y = (1080 / v->width) * 0.8;
		v->scaling_z = 3;
	}
	v->trans_x = 1920 / 2;
	v->trans_y = 1080 / 2;
}

void	 transformations(t_colect *v, int next_i, int next_j)
{
	scaling(v, next_i, next_j);
	isometric(v, &v->x, &v->y, v->tab_z[v->j][v->i]);
	isometric(v,&v->x1, &v->y1, v->tab_z[next_j][next_i]);
	translation(v, &v->x, &v->y);
	translation(v, &v->x1, &v->y1);
}

int	destroy(void)
{
	exit(0);
	return (0);
}

int esc(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);	
}

void chek_leak(void) //!!!!!!!!!
{
    system("leaks fdf");
}

int	main(int ac, char **av)
{
	t_colect	v;
    atexit(chek_leak);//!!!!!!!!
	/// understind rotation and isometric // mlx function
	if (ac != 2)
		ft_error("Invalid number of arguments.\n");
	get_data(&v, av);
	transformations_parameter(&v);
	v.mlx.init = mlx_init();
	v.mlx.win = mlx_new_window(v.mlx.init, 1920, 1080, "FdF");
	v.mlx.img = mlx_new_image(v.mlx.init, 1920, 1080);
	v.mlx.adr = mlx_get_data_addr(v.mlx.img, &v.mlx.bit_pxl, &v.mlx.line,
			&v.mlx.end);
	drawing(&v);
    mlx_hook(v.mlx.win, 2, 0, esc, &v);//????
    mlx_hook(v.mlx.win, 17, 0, destroy, &v);//???
	mlx_put_image_to_window(v.mlx.init, v.mlx.win, v.mlx.img, 0, 0);
	mlx_loop(v.mlx.init);
}
 