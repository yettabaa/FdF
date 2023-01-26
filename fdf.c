/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:42 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/26 05:27:53 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void init_transformations(t_colect *v)
{
	v->scaling_x = 50;
	v->scaling_y = 50;
	v->scaling_z = 1;
	v->trans_x = 600;
	v->trans_y = 500;
	v->angle_x = to_radians(0);
	v->angle_y = to_radians(90);
	v->angle_z = to_radians(0);
}

void	drawing(t_mlx img, t_colect v)
{
	init_transformations(&v);
	v.j = -1;
	while (++v.j < v.hiegth)
	{
		v.i = -1;
		while (++v.i < v.width)
		{
			if (v.i < v.width - 1)
			{
				transformations(&v, v.i+1, v.j);
				dda(img, v);
			}
			if (v.j < v.hiegth - 1)
			{
				transformations(&v, v.i, v.j + 1);
				dda(img, v);
			}
		}
	}
}

int	key(int keycode, t_mlx *vars)
{
	int	i;
	
	i = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 126)
	{
		i += 1;
		printf("%d\n", i);
	}
	return (0);
}

int	destroy(t_mlx *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	img;
	t_colect	v;

	/// check if file exists
	if (ac != 2)
		exit(1);
	get_data(&v, av);
	printf("x = %d, y = %d\n", v.width, v.hiegth);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1920, 1080, "FdF");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	drawing(img, v);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, 2, 0, &key, &img);
	mlx_hook(img.win, 17, 0, &destroy, &img);
	mlx_loop(img.mlx);
}

// int main (int ac ,char **av)
// {
//     if (ac != 2)
//         exit(1);
// 	t_colect v;
//     int i = -1, j = -1;
//     // int y,x;
//     // // char **s = get_next_line(av[1], &y);
//     // int **tab_z;
//     // int **tab_color;
//     // tab_z = get_data(av,&tab_color, &x, &y);
//     get_data(&v, av);
//     printf("x = %d, y = %d\n", v.width, v.hiegth);
//     while (++j < v.hiegth)
//     {
//         i = -1;
//         while (++i < v.width)
//             printf("%d ", v.tab_z[j][i]);
//         printf("\n");
//     }
// }
