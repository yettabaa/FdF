/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:42 by yettabaa          #+#    #+#             */
/*   Updated: 2022/12/24 21:55:08 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_corner(void *mlx, void **imgs, void *mlx_win, int **tab, int x, int y)
{
    int pos_x = 120;
    int pos_y;
    int lx = 0, ly = 0;
    int zome_x = 16;
    int zome_y = 32;
    while (lx < x && ly < y)
    {
        while (pos_x < 120 + ((lx + 1) * zome_x) && lx < x - 1)
        {
            draw_point(mlx, imgs, mlx_win,16777215,  (pos_x - pos_y) * cos((float)0.8 ), 140 + (zome_y * ly));
            pos_x++;
        }
        pos_y = 140 + zome_y * ly;
        while (pos_y < 140 + zome_y * (ly + 1) && ly < y - 1 )
        {
            draw_point(mlx, imgs, mlx_win, 16777215, 120 + (zome_x * lx), (pos_x + pos_y) * sin((float)0.8) - tab[ly][lx]);
            pos_y++;
        }
        if (lx == x - 1)
        {
            lx = -1;
            pos_x = 120;
            ly++;
        }
        lx++;
    }
}

int main (int ac ,char **av)
{
    // int fd;
    t_fdf pxl;
    
    if (ac != 2)
        exit(1);
    int **tab_color;
    int **tab_z;
    get_z_coordinates(av[1], &tab_z, &tab_color, &pxl.x, &pxl.y);  
	pxl.mlx = mlx_init();
    printf("x = %d, y = %d\n", pxl.x, pxl.y);
    // window_mlx(pxl.mlx, &pxl.imgs, &pxl.mlx_win, pxl.x * 28, pxl.y * 37);
    window_mlx(&pxl);
    draw_corner(pxl.mlx, &pxl.imgs, pxl.mlx_win, tab_z ,pxl.x, pxl.y);
    mlx_loop(pxl.mlx);
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
//     get_z_coordinates(&tab_z,&tab_color, av[1], &x, &y);
//     printf("x = %d, y = %d\n", x, y);
//     while (++j < y)
//     {
//         i = -1;
//         while (++i < x)
//             printf("%d ", tab_color[j][i]);
//         printf("\n");
//     }
// }
