/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:34:31 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/24 22:00:18 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void dda(t_mlx img, int color, double x, double y, double x1, double y1)
{
    int i;
    double xinc;
    double yinc;
    double steps;
    
    steps = fmax(fabs(x - x1), fabs(y - y1));
    // in cas x1 inc  to x (x - x1)
    xinc = (x1 - x) / steps;
    yinc = (y1 - y) / steps;
    i = 0;
    // printf("|xinc = %f|   |yinc = %f|\n", xinc,yinc);
    while (i <= steps)
    {
        // printf("x = %f, y = %f\n", x, y);
        if (round(x) >= 0 &&  round(x) < 1920 && round(y) >= 0 && round(y) < 1080)
            my_mlx_pixel_put(&img, round(x), round(y), color);
        x = x + xinc;
        y = y + yinc;
        i++;
    }
}