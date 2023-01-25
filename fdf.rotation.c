/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:13:21 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/25 04:14:22 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double to_degrees(double radians)
{
    return radians * (180.0 / M_PI);
}
double to_radians(double degree) 
{
    return (degree * (M_PI / 180));
}
void rotation(int *x, int *y, int z)
{
    int px;
    int py;
    int pz;
    double angx;
    double angy;
    double angz;
    
    angx = to_radians(30);
    angy = to_radians(30);
    angz = to_radians(0);

    px = *x;
    py = *y;
    pz = z;
    
    *x = px;
    *y = py * cos(angx) - (pz * sin(angx));
	z = py * sin(angx) + pz * cos(angx);
    
    px = *x * cos(angy) + z * sin(angy);
	py = *y;
	pz = *x * -sin(angy) + z * cos(angy);
    
    *x = px * cos(angz) + py * -sin(angz);
	*y = px * sin(angz) + py * cos(angz);
	z = pz;
}
