/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:42 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/28 21:28:25 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void transformations_parameter(t_colect *v)
{
	// direction of rotation
	v->scaling_x = (1080 / v->width);
	v->scaling_y = (1080 / v->width);
	v->scaling_z = 2;
	// v->angle_x = 45;
	// v->angle_y = -45;
	// v->angle_z = 30;
	v->angle_x = 60;
	v->angle_y = -35;
	v->angle_z = 15;
	v->trans_x = 1920 / 2;
	v->trans_y = 1080 / 2;
}

void	 transformations(t_colect *v, int next_i, int next_j)
{
	scaling(v, next_i, next_j);
	rotation(v, &v->x, &v->y, v->tab_z[v->j][v->i]);
	rotation(v, &v->x1, &v->y1, v->tab_z[next_j][next_i]);
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
	/// aderstind rotation and isometric // mlx function // information in the window
	if (ac != 2)
		ft_error("Invalid number of arguments.\n");
	get_data(&v, av);
	transformations_parameter(&v);
	v.mlx.init = mlx_init();
	v.mlx.win = mlx_new_window(v.mlx.init, 1920, 1080, "FdF");
	v.mlx.img = mlx_new_image(v.mlx.init, 1920, 1080);
	v.mlx.addr = mlx_get_data_addr(v.mlx.img, &v.mlx.bits_per_pixel, &v.mlx.line_length,
			&v.mlx.endian);
	printf("x = %d, y = %d\n", v.width, v.hiegth);//!!!!!!!!
	drawing(&v);
	mlx_put_image_to_window(v.mlx.init, v.mlx.win, v.mlx.img, 0, 0);
	mlx_hook(v.mlx.win, 2, 0, key, &v);
	mlx_mouse_hook(v.mlx.win, mouse, &v);
	mlx_hook(v.mlx.win, 17, 0, destroy, &v);
	mlx_loop(v.mlx.init);
}
