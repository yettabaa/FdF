/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:42 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/22 23:32:47 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// dx = |x1 - x2|
// dy = |y1 - y2|
// m = dy / dx
// steps = dy ?> dx
// xinc  dx / steps
// yinc  dy / steps
//max - abs - round -
// double x = round(0.6);
void dda(t_mlx img, int color, double x, double y, double x1, double y1)
{
    int i;
    double xinc;
    double yinc;
    double steps;
    
    steps = fmax(fabs(x - x1), fabs(y - y1));
    xinc = fabs(x - x1) / steps;
    yinc = fabs(y - y1) / steps;
    i = 0;
    while (i <= steps)
    {
        // printf("==>%f", y);
        my_mlx_pixel_put(&img, round(x), round(y), color);
        y = y + yinc;
        x = x + xinc;
        i++;
    }
}

void iso(int *x, int *y, int *x1, int *y1, t_data d, int i, int j)
{
    int xinc = 0, yinc =0;
    int starx, stary;
    
    xinc = (1920 / d.x) / 3;
    yinc = (1080 / d.y) / 2;
    // starx = (1920 / 2) - ((d.x * xinc) / 2);
    stary = (1080 / 2) - ((d.y * yinc) / 2);
    starx = 1000;
    stary = -200;
    // starx = 0;
    // stary = 0;
    *x = starx + (xinc * i);
    *y = stary + (yinc * j);
    *x1 = starx + (xinc * (i + 1));
    *y1 = stary + (yinc * (j + 1));
}
void iso_3d(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}
void drawing(t_mlx img, t_data d)
{
    int i;
    int j;
    int x, y, x1, y1;
    
    j = 0;
    while (j < d.y)
    {
        i = 0;
        while (i < d.x)
        {
            iso(&x, &y, &x1, &y1, d, i, j);
            iso_3d(&x, &y, d.tab_z[j][i]);
            iso_3d(&x1, &y1, d.tab_z[j][i]);
            if (i < d.x - 1)
                dda(img, d.tab_c[j][i], x, y, x1, y);
            if (j < d.y - 1)
                dda(img, d.tab_c[j][i], x, y, x, y1);
            // x = x1;
            // y = y1;
            // break;
            // printf("%f  ", fabs(round((x + y) * sin(0.8) - d.tab_z[j][i])));
            // dda(img, d.tab_c[j][i], round(fabs(x - y) * cos(0.523599)),  fabs(round((x + y) * sin(0.523599) - d.tab_z[j][i])), round(fabs(x1 - y) * cos(0.523599)),  fabs(round((x + y1) * sin(0.523599) - d.tab_z[j][i])));
            // dda(img, d.tab_c[j][i], round(fabs(x - y) * cos(0.523599)),  fabs(round((x + y) * sin(0.523599) - d.tab_z[j][i])), round(fabs(x1 - y) * cos(0.523599)),  fabs(round((x + y1) * sin(0.523599) - d.tab_z[j][i])));
            i++;
        }
        // if (j == 1)
        //     break;
        j++;
    }
    
    
}

int main (int ac ,char **av)
{
	void	*mlx;
	void	*mlx_win;
    // char **maps;
	t_mlx	img;
    t_data  d;
    if (ac != 2)
        exit(1);
    // d.maps = get_next_line(av[1], &d.y);     
    d.tab_z = get_data(av,&d.tab_c, &d.x, &d.y);  
    printf("x = %d, y = %d\n", d.x, d.y);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1920);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    // draw_corner(img, d);
    // dda(img, d, 0, 0, 1919, 1079);
    drawing(img, d);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}


// int main (int ac ,char **av)
// {
//     if (ac != 2)
//         exit(1);
//     int i = -1, j = -1;
//     int y,x;
//     // char **s = get_next_line(av[1], &y);
//     int **tab_z;
//     int **tab_color;
//     tab_z = get_data(av,&tab_color, &x, &y);  
//     printf("x = %d, y = %d\n", x, y);
//     while (++j < y)
//     {
//         i = -1;
//         while (++i < x)
//             printf("%d ", tab_color[j][i]);
//         printf("\n");
//     }
// }
