/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transformations3D.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:13:21 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/26 05:26:48 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void translation(t_colect *v, double *x, double *y)
{
	*x = *x + v->trans_x;
	*y = *y + v->trans_y;
}

void scaling(t_colect *v, int next_i, int next_j)
{
	v->x = v->i * v->scaling_x;
	v->y = v->j * v->scaling_y;
	v->x1 = next_i * v->scaling_x;
	v->y1 = next_j * v->scaling_y;
}
double	to_radians(double degree)
{
	return (degree * (M_PI / 180));
}

void	rotation(t_colect *v, double *x, double *y, double z)
{
	double	px;
	double	py;
	double	pz;

	px = *x;
	py = *y;
	pz = z * v->scaling_z;
	*y = py * cos(v->angle_x) - (pz * sin(v->angle_x));
	z = py * sin(v->angle_x) + (pz * cos(v->angle_x));
	px = *x * cos(v->angle_y) + (z * sin(v->angle_y));
	py = *y;
	pz = *x * -sin(v->angle_y) + (z * cos(v->angle_y));
	*x = px * cos(v->angle_z) + (py * -sin(v->angle_z));
	*y = px * sin(v->angle_z) + (py * cos(v->angle_z));
}
void isometric(t_colect *v, double *x, double *y, double z)
{
    double px;
    double py;
    
    px = *x;
    py = *y;
    *x = (px - py) * cos(to_radians(20));
    *y = -v->scaling_z * z + (px + py) * sin(to_radians(10));
}
void	 transformations(t_colect *v, int next_i, int next_j)
{
	scaling(v, next_i, next_j);
	rotation(v, &v->x, &v->y, v->tab_z[v->j][v->i]);
	rotation(v, &v->x1, &v->y1, v->tab_z[next_j][next_i]);
	// isometric(v,&v->x, &v->y, v->tab_z[v->j][v->i]);
	// isometric(v,&v->x1, &v->y1, v->tab_z[next_j][next_i]);
	translation(v, &v->x, &v->y);
	translation(v, &v->x1, &v->y1);
}