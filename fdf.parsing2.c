/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:39:53 by yettabaa          #+#    #+#             */
/*   Updated: 2022/12/23 03:42:48 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	cheker_z(char *str)
{
	char	**spl_vrg;
	int		z;
	int		i;

	i = -1;
	spl_vrg = ft_split(str, ',');
	z = ft_atoi(spl_vrg[0]);
	free_strs(spl_vrg);
	return (z);
}

int	**get_z_coordinates(char **maps, int x, int y)
{
	int		**tab;
	char	**strs;
	int		i;

	tab = malloc(sizeof(int *) * y);
	if (!tab)
		return (NULL);
	while (y--)
	{
		i = -1;
		strs = ft_split(maps[y], ' ');
		tab[y] = malloc(sizeof(int) * x);
		if (!tab[y])
			return (NULL);
		while (++i < x)
			tab[y][i] = cheker_z(strs[i]);
		free_strs(strs);
	}
	free_strs(maps);
	// system("leaks fdf");
	return (tab);
}

int	cheker_colors(char *str)
{
	char	**spl;
	int		colors;
	int		i;

	i = -1;
	spl= ft_split(str, ',');
	if (!spl[1] && !ft_strchr(str, ','))
		colors = 16777215;
	else if (!ft_strncmp(spl[1], "0x", 2) || !ft_strncmp(spl[1], "0X",2))
		colors = ft_atoi_hexa(spl[1]);
	else
		colors = ft_atoi(spl[1]);
	free_strs(spl);
	return (colors);
}

int	**get_colors(char **maps, int x, int y)
{
	int		**tab;
	char	**strs;
	int		i;

	tab = malloc(sizeof(int *) * y);
	if (!tab)
		return (NULL);
	while (y--)
	{
		i = -1;
		strs = ft_split(maps[y], ' ');
		tab[y] = malloc(sizeof(int) * x);
		if (!tab[y])
			return (NULL);
		while (++i < x)
			tab[y][i] = cheker_colors(strs[i]);
		free_strs(strs);
	}
	free_strs(maps);
	// system("leaks fdf");
	return (tab);
}
