/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transformations3D.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:13:21 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/26 03:24:58 by yettabaa         ###   ########.fr       */
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
    
	*x = px;
	*y = py * cos(v->angle_x) - (pz * sin(v->angle_x));
	z = py * sin(v->angle_x) + pz * cos(v->angle_x);
    
	px = *x * cos(v->angle_y) + z * sin(v->angle_y);
	py = *y;
	pz = *x * -sin(v->angle_y) + z * cos(v->angle_y);
    
	*x = px * cos(v->angle_z) + py * -sin(v->angle_z);
	*y = px * sin(v->angle_z) + py * cos(v->angle_z);
	z = pz;
}

void	 transformations(t_colect *v, int next_i, int next_j)
{
	scaling(v, next_i, next_j);
	rotation(v, &v->x, &v->y, v->tab_z[v->j][v->i]);
	rotation(v, &v->x1, &v->y1, v->tab_z[next_j][next_i]);
	translation(v, &v->x, &v->y);
	translation(v, &v->x1, &v->y1);
}