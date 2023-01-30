/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:42 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/30 05:30:37 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void transformations_parameter_bonus(t_colect *v)
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
	v->angle_x = 45;
	v->angle_y = 45;
	v->angle_z = -35;
	v->trans_x = 1920 / 2;
	v->trans_y = 1080 / 2;
	v->option_color = 0;
	put_info(v);
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
	// char	*relative_path = "./test.xpm";
	atexit(chek_leak);//!!!!!!!!
	/// aderstind rotation and isometric // mlx function // information in the window
	if (ac != 2)
		ft_error("Invalid number of arguments.\n");
	v.mlx.init = mlx_init();
	v.mlx.win = mlx_new_window(v.mlx.init, 2170, 1080, "FdF");
	get_data(&v, av);
	transformations_parameter_bonus(&v);
	v.mlx.img = mlx_new_image(v.mlx.init, 1920, 1080);
	v.mlx.adr = mlx_get_data_addr(v.mlx.img, &v.mlx.bit_pxl, &v.mlx.line, &v.mlx.end);
	printf("x = %d, y = %d\n", v.width, v.hiegth);
	drawing(&v);
	mlx_put_image_to_window(v.mlx.init, v.mlx.win, v.mlx.img, 250, 0);
	mlx_mouse_hook(v.mlx.win, mouse, &v);
	mlx_hook(v.mlx.win, 2, 0, key, &v);
	mlx_hook(v.mlx.win, 17, 0, destroy, &v);
	mlx_loop(v.mlx.init);
}
