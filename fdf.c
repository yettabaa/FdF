/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:29:05 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/28 19:46:21 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void transformations_parameter(t_colect *v)
{
	v->scaling_x = (1080 / v->width);
	v->scaling_y = (1080 / v->width);
	v->scaling_z = 2;
	v->trans_x = 1920 / 2;
	v->trans_y = 1080 / 2;
	// v->angle_x = 45;
	// v->angle_y = 45;
	// v->angle_z = -30;
}
void	 transformations(t_colect *v, int next_i, int next_j)
{
	scaling(v, next_i, next_j);
	// rotation(v, &v->x, &v->y, v->tab_z[v->j][v->i]);
	// rotation(v, &v->x1, &v->y1, v->tab_z[next_j][next_i]);
	isometric(&v->x, &v->y, v->tab_z[v->j][v->i]);
	isometric(&v->x1, &v->y1, v->tab_z[next_j][next_i]);
	translation(v, &v->x, &v->y);
	translation(v, &v->x1, &v->y1);
}
int	destroy(void)
{
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
	v.init = mlx_init();
	v.win = mlx_new_window(v.init, 1920, 1080, "FdF");
	v.img = mlx_new_image(v.init, 1920, 1080);
	v.addr = mlx_get_data_addr(v.img, &v.bits_per_pixel, &v.line_length,
			&v.endian);
	drawing(&v);
    mlx_hook(v.win, 2, 0, destroy, &v);//????
    mlx_hook(v.win, 17, 0, destroy, &v);//???
	mlx_put_image_to_window(v.init, v.win, v.img, 0, 0);
	mlx_loop(v.init);
}
