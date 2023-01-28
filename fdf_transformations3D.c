/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transformations3D.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:13:21 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/28 20:06:52 by yettabaa         ###   ########.fr       */
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
	// you need to update the cordonates in the midle for a rotate in the midle
	v->x = v->i * v->scaling_x - (v->width - 1) *v->scaling_x / 2;
	v->y = v->j * v->scaling_y - (v->hiegth - 1) *v->scaling_y / 2;
	v->x1 = next_i * v->scaling_x - (v->width - 1) *v->scaling_x / 2;
	v->y1 = next_j * v->scaling_y - (v->hiegth - 1) *v->scaling_y / 2;
}
double	rad(double degree)
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

	*y = py * cos(rad(v->angle_x)) - (pz * sin(rad(v->angle_x)));
	z = py * sin(rad(v->angle_x)) + (pz * cos(rad(v->angle_x)));
	
	px = *x * cos(rad(v->angle_y)) + (z * sin(rad(v->angle_y)));
	py = *y;
	pz = *x * -sin(rad(v->angle_y)) + (z * cos(rad(v->angle_y)));
	
	*x = px * cos(rad(v->angle_z)) + (py * -sin(rad(v->angle_z)));
	*y = px * sin(rad(v->angle_z)) + (py * cos(rad(v->angle_z)));
}

void isometric(double *x, double *y, double z)
{
    double px;
    double py;
    
    px = *x;
    py = *y;
    // *x = px * cos(to_rad(30)) + (-z * sin(to_rad(30)));
    // *y = ( -px * sin(to_rad(30))) + py * cos(to_rad(30)) + z * sin(to_rad(30)) * cos(to_rad(30));
    *x = (px - py) * cos(rad(30));
    *y = -z + (px + py) * sin(rad(30));
}
