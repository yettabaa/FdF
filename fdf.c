/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:42 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/25 04:35:30 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void cordonate_to_pixel(int *x, int *y, t_data d, int i, int j)
{
    int xinc = 0, yinc =0;
    int starx, stary;
    
    xinc = (1920 / d.x) / 2;
    yinc = (1080 / d.y) / 2;
    // starx = (1920 / 2) - ((d.x * xinc) / 2);
    // stary = (1080 / 2) - ((d.y * yinc) / 2);
    starx = 0;
    stary = 0;
    // *x = starx  + (xinc * i);
    // *y = stary + (yinc * j);
    *x = xinc * i;
    *y = yinc * j;
}

void isometric(int *x, int *y, int z)
{
    int px;
    int py;
    
    px = *x;
    py = *y;
    *x = (px - py) * cos(to_radians(20));
    *y = -z + (px + py) * sin(to_radians(10));
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
            if (i < d.x - 1)
            {
                cordonate_to_pixel(&x, &y, d, i, j);
                cordonate_to_pixel(&x1, &y1, d, i + 1, j);
                // isometric(&x, &y, d.tab_z[j][i]);
                // isometric(&x1, &y1, d.tab_z[j][i + 1]);
                rotation(&x, &y, d.tab_z[j][i]);
                rotation(&x1, &y1, d.tab_z[j][i + 1]);
                x = x * 2;
                x1 = x1 * 2;
                y = y * 2;
                y1 = y1 * 2;
                x = x + 500;
                x1 = x1 + 500;
                y = y + 500;
                y1 = y1 + 500;
                dda(img, d.tab_c[j][i], x , y, x1, y1);
                // printf("x = %d, y = %d\n", x, y);
                // printf("x1 = %d, y1 = %d\n", x1,y1);
            }
            if (j < d.y - 1)
            {
                // cordonate_to_pixel(&x, &y, &x1, &y1, d, i, j);
                cordonate_to_pixel(&x, &y, d, i, j);
                cordonate_to_pixel(&x1, &y1, d, i, j + 1);
                // isometric(&x, &y, d.tab_z[j][i]);
                // isometric(&x1, &y1, d.tab_z[j+ 1][i]);
                rotation(&x, &y, d.tab_z[j][i]);
                rotation(&x1, &y1, d.tab_z[j+ 1][i]);
                x = x * 2;
                x1 = x1 * 2;
                y = y * 2;
                y1 = y1 * 2;
                x = x + 500;
                x1 = x1 + 500;
                y = y + 500;
                y1 = y1 + 500;
                dda(img, d.tab_c[j][i], x , y, x1   , y1);
            }
            // if (i == 1)
            //     break;
            i++;
        }
        // if (j == 1)
        // break;
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
	mlx_win = mlx_new_window(mlx, 1920, 1080, "FdF");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    // dda(img, 16777215, 1920 / 2, 0, 0, 1080 / 2);
    // dda(img, 16777215, 0, 50, 50, 0);
    // dda(img, 16777215, 50, 0, 0, 50);
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
