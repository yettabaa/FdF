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

void	put_info(t_colect *v)
{
	t_info	h;

	h.image = mlx_new_image(v->mlx.init, INFO_WIDTH, HIEGTH);
	v->mlx.adr = mlx_get_data_addr(h.image, &v->mlx.bit_pxl, &v->mlx.line,
			&v->mlx.end);
	h.y = -1;
	while (++h.y < HIEGTH)
	{
		h.x = -1;
		while (++h.x < INFO_WIDTH)
			my_mlx_pixel_put(v, h.x, h.y, 0x060a24);
	}
	mlx_put_image_to_window(v->mlx.init, v->mlx.win, h.image, 0, 0);
	h.z = ft_strjoin("Z = ", ft_itoa(v->scaling_z));
	h.zoom = ft_strjoin("Zoom = ", ft_itoa(v->scaling_x));
	h.rx = ft_strjoin("Rotations(X)° = ", ft_itoa(v->angle_x));
	h.ry = ft_strjoin("Rotations(Y)° = ", ft_itoa(v->angle_y));
	h.rz = ft_strjoin("Rotations(Z)° = ", ft_itoa(v->angle_z));
	mlx_string_put(v->mlx.init, v->mlx.win, 15, HIEGTH * 0.03, 16777215, h.z);
	mlx_string_put(v->mlx.init, v->mlx.win, 15, HIEGTH * 0.06, 16777215, h.zoom);
	mlx_string_put(v->mlx.init, v->mlx.win, 15, HIEGTH * 0.09, 16777215, h.rx);
	mlx_string_put(v->mlx.init, v->mlx.win, 15, HIEGTH * 0.12, 16777215, h.ry);
	mlx_string_put(v->mlx.init, v->mlx.win, 15, HIEGTH * 0.15, 16777215, h.rz);
	mlx_string_put(v->mlx.init, v->mlx.win, 15, HIEGTH * 0.5, 0xDAA520, "Altitude : +/-");
	mlx_string_put(v->mlx.init, v->mlx.win, 15, HIEGTH * 0.53, 0xDAA520, "Marvelous color : C/X");
	mlx_string_put(v->mlx.init, v->mlx.win, 15, HIEGTH * 0.56, 0xDAA520, "Zoom In / Out :");
	mlx_string_put(v->mlx.init, v->mlx.win, 45, HIEGTH * 0.59, 16777215, "Scroll mouse");
	mlx_string_put(v->mlx.init, v->mlx.win, 15, HIEGTH * 0.62, 0xDAA520, "Init view : Right click");
	mlx_string_put(v->mlx.init, v->mlx.win, 15, HIEGTH * 0.65, 0xDAA520, "Any place : Left click");
	mlx_string_put(v->mlx.init, v->mlx.win, 15, HIEGTH * 0.68, 0xDAA520, "Multi view :");
	mlx_string_put(v->mlx.init, v->mlx.win, 45, HIEGTH * 0.71, 16777215, "2D view : P");
	mlx_string_put(v->mlx.init, v->mlx.win, 45, HIEGTH * 0.74, 16777215, "Horizontal view : H");
	mlx_string_put(v->mlx.init, v->mlx.win, 45, HIEGTH * 0.77, 16777215, "Vertical view : V");
	mlx_string_put(v->mlx.init, v->mlx.win, 15, HIEGTH * 0.8, 0xDAA520, "Rotate :");
	mlx_string_put(v->mlx.init, v->mlx.win, 45, HIEGTH * 0.83, 16777215, "X-Axis : 2/8");
	mlx_string_put(v->mlx.init, v->mlx.win, 45, HIEGTH * 0.86, 16777215, "Y-Axis : 4/6");
	mlx_string_put(v->mlx.init, v->mlx.win, 45, HIEGTH * 0.89, 16777215, "Z-Axis : 7/9");
	mlx_string_put(v->mlx.init, v->mlx.win, 15, HIEGTH * 0.92, 0xDAA520, "Translation :");
	mlx_string_put(v->mlx.init, v->mlx.win, 45, HIEGTH * 0.95, 16777215, "keyboard arrow");
	free(h.z);
	free(h.rx);
	free(h.zoom);
	free(h.ry);
	free(h.rz);
	mlx_destroy_image(v->mlx.init, h.image);
}