/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:34:31 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/26 01:00:35 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void dda(t_mlx img, t_colect v)
{
    int i;
    double xinc;
    double yinc;
    double steps;
    
    steps = fmax(fabs(v.x - v.x1), fabs(v.y - v.y1));
    // in cas x1 inc  to x (x - x1)
    xinc = (v.x1 - v.x) / steps;
    yinc = (v.y1 - v.y) / steps;
    i = 0;
    // printf("|xinc = %f|   |yinc = %f|\n", xinc,yinc);
    while (i <= steps)
    {
        // printf("x = %f, y = %f\n", x, y);
        if (round(v.x) >= 0 &&  round(v.x) < 1920 && round(v.y) >= 0 && round(v.y) < 1080)
            my_mlx_pixel_put(&img, round(v.x), round(v.y), v.tab_c[v.j][v.i]);
        v.x = v.x + xinc;
        v.y = v.y + yinc;
        i++;
    }
}