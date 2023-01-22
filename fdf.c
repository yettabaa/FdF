/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:42 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/22 05:43:06 by yettabaa         ###   ########.fr       */
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
// void draw_corner(t_data *img, int x, int y, int **tab_z, int **tab_c)
// double x = round(0.6);
// void draw_corner(t_mlx img, t_data d)
// {
//     int pos_x = 120;
//     int pos_y = 140;
//     int lx = 0, ly = 0;
//     int zome_x = 32;
//     int zome_y = 30;
    
//     while (lx < d.x && ly < d.y)
//     {
//         while (pos_x <= 120 + ((lx + 1) * zome_x) && lx < d.x - 1)
//         {
//             // my_mlx_pixel_put(img,  (pos_x - pos_y) * cos((float)0.8), 140 + (zome_y * ly), tab_c[ly][lx]);
//             my_mlx_pixel_put(&img,  pos_x, 140 + (zome_y * ly), d.tab_c[ly][lx]);
//             pos_x++;
//         }
//         pos_y = 140 + zome_y * ly;
//         while (pos_y <= 140 + zome_y * (ly + 1) && ly < d.y - 1 )
//         {
//             // my_mlx_pixel_put(img, 120 + (zome_x * lx),  (pos_x + pos_y) * sin((float)0.8) - tab_z[ly][lx], tab_c[ly][lx]);
//             my_mlx_pixel_put(&img, 120 + (zome_x * lx),  pos_y, d.tab_c[ly][lx]);
//             pos_y++;
//         }
//         if (lx == d.x - 1)
//         {
//             lx = -1;
//             pos_x = 120;
//             ly++;
//         }
//         lx++;
//     }
// }
void dda(t_mlx img, t_data d, double x, double y, double x1, double y1)
{
    int i;
    double xinc;
    double yinc;
    double steps;
    
    steps = fmax(fabs(x - x1), fabs(y - y1));
    xinc = fabs(x - x1) / steps;
    yinc = fabs(y - y1) / steps;
    i = 0;
    while (i < steps)
    {
        y = y + yinc;
        x = x + xinc;
        // printf("==>%f", y);
        my_mlx_pixel_put(&img, round(x), round(y), 16777215);
        i++;
    }
}

void drawing(t_mlx img, t_data d)
{
    int ix = 0, iy = 0;
    int starx, stary;
    int xinc = 0, yinc =0;
    
    xinc = (1920 / d.x) / 3;
    yinc = (1080 / d.y) / 3;
    starx = (1920 / 2) - ((d.x * xinc) / 2);
    stary = (1080 / 2) - ((d.y * yinc) / 2);

    while (iy < d.y)
    {
        ix = 0;
        while (ix < d.x)
        {
            // printf("%d  ", starx + (xinc * (ix + 1)));
            // printf("%d  ",  (yinc * (iy + 1)));
            // puts("ss");
            dda(img, d, starx + (xinc * ix), stary + (yinc * iy),        starx + (xinc * (ix + 1)),    stary + (yinc * iy));
            dda(img, d, starx + (xinc * ix), stary + (yinc * iy),        starx + (xinc * ix),          stary + (yinc * (iy + 1)));
            // break;
            // starx = starx + (xinc * (ix + 1));
            ix++;
        }
        // stary = stary + (yinc * (iy + 1));
        iy++;
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
	img.img = mlx_new_image(mlx, 1920, 1080);
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
