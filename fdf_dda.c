/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:34:31 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/28 19:51:39 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_colect *v, int x, int y, int color)
{
	char	*dst;

	dst = v->mlx.addr + (y * v->mlx.line_length + x * (v->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void dda(t_colect *v)
{
    int i;
    double xinc;
    double yinc;
    double steps;
    
    steps = fmax(fabs(v->x - v->x1), fabs(v->y - v->y1));
    // in cas x1 inc  to x (x - x1)
    xinc = (v->x1 - v->x) / steps;
    yinc = (v->y1 - v->y) / steps;
    i = 0;
    while (i <= steps)
    {
        if (round(v->x) >= 0 &&  round(v->x) < 1920 && round(v->y) >= 0 && round(v->y) < 1080)
            my_mlx_pixel_put(v, round(v->x), round(v->y), v->tab_c[v->j][v->i]);
        v->x = v->x + xinc;
        v->y = v->y + yinc;
        i++;
    }
}

void	drawing(t_colect *v)
{
	v->j = -1;
	while (++v->j < v->hiegth)
	{
		v->i = -1;
		while (++v->i < v->width)
		{
			if (v->i < v->width - 1)
			{
				transformations(v, v->i + 1, v->j);
				dda(v);
			}
			if (v->j < v->hiegth - 1)
			{
				transformations(v, v->i, v->j + 1);
				dda(v);
			}
		}
	}
}