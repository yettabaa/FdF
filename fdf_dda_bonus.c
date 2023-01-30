/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dda_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:43:58 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/30 22:28:41 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_colect *v, int x, int y, int color)
{
	char	*dst;

	dst = v->mlx.adr + (y * v->mlx.line + x * (v->mlx.bit_pxl / 8));
	*(unsigned int *)dst = color;
}

static void	dda_bonus(t_colect *v, int next_i, int next_j)
{
	int		i;
	double	xinc;
	double	yinc;
	double	steps;
	double	prc;

	steps = fmax(fabs(v->x - v->x1), fabs(v->y - v->y1));
	xinc = (v->x1 - v->x) / steps;
	yinc = (v->y1 - v->y) / steps;
	i = 0;
	while (i <= steps)
	{
		prc = ft_percent(i, steps);
		if (v->option_color == 0)
			v->color = ft_gradient(v->tab_c[v->j][v->i],
					v->tab_c[next_j][next_i], prc);
		else
			v->color = v->tab_c[v->j][v->i] >> (i % 10);
		if (round(v->x) >= 0 && round(v->x) < 1920 && round(v->y) >= 0
			&& round(v->y) < 1080)
			my_mlx_pixel_put(v, round(v->x), round(v->y), v->color);
		v->x = v->x + xinc;
		v->y = v->y + yinc;
		i++;
	}
}

void	drawing_bonus(t_colect *v)
{
	v->j = -1;
	while (++v->j < v->hiegth)
	{
		v->i = -1;
		while (++v->i < v->width)
		{
			if (v->i < v->width - 1)
			{
				transformations_bonus(v, v->i + 1, v->j);
				dda_bonus(v, v->i + 1, v->j);
			}
			if (v->j < v->hiegth - 1)
			{
				transformations_bonus(v, v->i, v->j + 1);
				dda_bonus(v, v->i, v->j + 1);
			}
		}
	}
}
