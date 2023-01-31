/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_gradient_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:19:34 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/31 04:50:01 by yettabaa         ###   ########.fr       */
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

static int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	ft_gradient(int start_color, int end_color, double percent)
{
	int	grad[4];

	grad[0] = (int)round((1 - percent) * get_b(start_color) + percent
			* get_b(end_color));
	grad[1] = (int)round((1 - percent) * get_g(start_color) + percent
			* get_g(end_color));
	grad[2] = (int)round((1 - percent) * get_r(start_color) + percent
			* get_r(end_color));
	grad[3] = (int)round((1 - percent) * get_t(start_color) + percent
			* get_t(end_color));
	return (grad[3] << 24 | grad[2] << 16 | grad[1] << 8 | grad[0]);
}
