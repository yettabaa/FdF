/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:05:42 by yettabaa          #+#    #+#             */
/*   Updated: 2022/12/23 15:28:19 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_corner(void *mlx, void **imgs, void *mlx_win, int **tab, int x, int y)
{
    int pos_x = 120;
    int pos_y;
    int lx = 0 , ly = 0;
    int zome_x = 30;
    int zome_y = 32;
    while (lx < x && ly < y)
    {
        // puts("sss");
        while (pos_x++ < 120 + ((lx + 1) * zome_x))
            draw_point(mlx, imgs, mlx_win,tab[ly][lx], pos_x - 1, 140 + (zome_y * ly));
        pos_y = 140 + (zome_y * ly);
        while (pos_y++ < 140 + ((ly + 1) * zome_y))
            draw_point(mlx, imgs, mlx_win, tab[ly][lx], 120 + (zome_x * lx), pos_y - 1);
        lx++;
        if (lx == x)
        {
            lx = 0;
            pos_x = 120;
            ly++;
        }
    }
}

// int main (int ac ,char **av)
// {
//     // int fd;
//     t_fdf pxl;
    
//     if (ac != 2)
//         exit(1);
    
//     char **s = gnl_maps_xy(av[1], &pxl.x, &pxl.y);  
// 	pxl.mlx = mlx_init();
//     printf("x = %d, y = %d\n", pxl.x, pxl.y);
//     // window_mlx(pxl.mlx, &pxl.imgs, &pxl.mlx_win, pxl.x * 28, pxl.y * 37);
//     window_mlx(&pxl);
//     draw_corner(pxl.mlx, &pxl.imgs, pxl.mlx_win, get_colors(s, pxl.x, pxl.y) ,pxl.x, pxl.y);
//     mlx_loop(pxl.mlx);
// }


int main (int ac ,char **av)
{
    if (ac != 2)
        exit(1);
    int i = -1, j = -1;
    int y,x;
    char **s = gnl_maps_xy(av[1], &x, &y);
    printf("x = %d, y = %d\n", x, y);
    int **tab = get_colors(s, x, y);
    while (++j < y)
    {
        i = -1;
        while (++i < x)
        {
            printf("%d ", tab[j][i]);
        }
        printf("\n");
    }
}
