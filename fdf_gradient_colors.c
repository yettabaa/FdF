/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_gradient_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:19:34 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/29 23:54:42 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

static int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

static int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

double	ft_percent(double i, double steps)
{
	if (steps == 0)
		return (1.0);
	else
		return (i / steps);
}

int	ft_gradient(int start, int end, double percent)
{
	int		new[4];

	new[0] = (int)round((1 - percent) * get_r(start) + percent * get_r(end));
	new[1] = (int)round((1 - percent) * get_g(start) + percent * get_g(end));
	new[2] = (int)round((1 - percent) * get_b(start) + percent * get_b(end));
	new[3] = end & (0xFF << 24);
	return (new[3] << 24 | new[0] << 16 | new[1] << 8 | new[2]);
}