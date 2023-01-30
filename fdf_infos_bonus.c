/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_infos_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:13:19 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/30 20:37:19 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_info
{
	void	*image;
	int		x;
	int		y;
	char	*z;
	char	*rx;
	char	*ry;
	char	*rz;
	char	*zoom;
	void	*in;
	void	*w;
}			t_info;

static void	str_put(t_colect *v, t_info h)
{
	h.in = v->mlx.init;
	h.w = v->mlx.win;
	h.ry = ft_strjoin("Rotations(Y)° = ", ft_itoa(v->angle_y));
	mlx_string_put(h.in, h.w, 15, 85, 16777215, h.ry);
	h.rz = ft_strjoin("Rotations(Z)° = ", ft_itoa(v->angle_z));
	mlx_string_put(h.in, h.w, 15, 110, 16777215, h.rz);
	mlx_string_put(h.in, h.w, 15, 650, 0xDAA520, "Altitude : +/-");
	mlx_string_put(h.in, h.w, 15, 675, 0xDAA520, "Marvelous color : C/X");
	mlx_string_put(h.in, h.w, 15, 700, 0xDAA520, "Zoom In / Out :");
	mlx_string_put(h.in, h.w, 45, 725, 16777215, "Scroll mouse");
	mlx_string_put(h.in, h.w, 15, 750, 0xDAA520, "Init view : Right click");
	mlx_string_put(h.in, h.w, 15, 800, 0xDAA520, "Multi view :");
	mlx_string_put(h.in, h.w, 45, 825, 16777215, "2D view : P");
	mlx_string_put(h.in, h.w, 45, 850, 16777215, "Horizontal view : H");
	mlx_string_put(v->mlx.init, v->mlx.win, 45, 875, 16777215,
		"Vertical view : V");
	mlx_string_put(h.in, h.w, 15, 900, 0xDAA520, "Rotate :");
	mlx_string_put(h.in, h.w, 45, 925, 16777215, "X-Axis : 2/8");
	mlx_string_put(h.in, h.w, 45, 950, 16777215, "Y-Axis : 4/6");
	mlx_string_put(h.in, h.w, 45, 975, 16777215, "Z-Axis : 7/9");
	mlx_string_put(h.in, h.w, 15, 1000, 0xDAA520, "Translation :");
	mlx_string_put(h.in, h.w, 45, 1025, 16777215, "keyboard arrow");
	free(h.ry);
	free(h.rz);
}

void	put_info(t_colect *v)
{
	t_info	h;

	h.image = mlx_new_image(v->mlx.init, 250, 1080);
	v->mlx.adr = mlx_get_data_addr(h.image, &v->mlx.bit_pxl, &v->mlx.line,
			&v->mlx.end);
	h.y = -1;
	while (++h.y < 1080)
	{
		h.x = -1;
		while (++h.x < 250)
			my_mlx_pixel_put(v, h.x, h.y, 0x060a24);
	}
	mlx_put_image_to_window(v->mlx.init, v->mlx.win, h.image, 0, 0);
	h.z = ft_strjoin("Z = ", ft_itoa(v->scaling_z));
	mlx_string_put(v->mlx.init, v->mlx.win, 15, 10, 16777215, h.z);
	h.zoom = ft_strjoin("Zoom = ", ft_itoa(v->scaling_x));
	mlx_string_put(v->mlx.init, v->mlx.win, 15, 35, 16777215, h.zoom);
	h.rx = ft_strjoin("Rotations(X)° = ", ft_itoa(v->angle_x));
	mlx_string_put(v->mlx.init, v->mlx.win, 15, 60, 16777215, h.rx);
	mlx_string_put(v->mlx.init, v->mlx.win, 15, 775, 0xDAA520,
		"Any place : Left click");
	free(h.z);
	free(h.rx);
	free(h.zoom);
	str_put(v, h);
}
