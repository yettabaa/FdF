/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:14:35 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/26 00:52:32 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	free_tab(int **tab, int y)
// {
// 	int	i;

// 	i = 0;
// 	while (i < y)
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// }

void	ft_error(const char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
//chek overflow
void	put_z_color(char *str, int *tab_z, int *tab_color)
{
	char	**spl_vrg;
	char	*color;
	
	spl_vrg = ft_split(str, ',');
	if (*str == ',')
	{
		*tab_z = 0;
		color = spl_vrg[0];
	}
	else
	{
		*tab_z = ft_atoi(spl_vrg[0]);
		color = spl_vrg[1];
	}	
	if (!color && !ft_strchr(str, ','))//===> if number befor , and exist nothing after , or if color dosn't exist 
		*tab_color = 16777215;
	else if (!color && ft_strchr(str, ',')) // if color not specifier
		*tab_color = 0;
	else if (!ft_strncmp(color, "0x", 2) || !ft_strncmp(color, "0X",2))
		*tab_color = ft_atoi_hexa(color);
	else
		*tab_color = ft_atoi(color);
	free_strs(spl_vrg);
}


void	get_data(t_colect *v, char **av)
{
	t_get_data s;

	s.maps = get_next_line(av[1], &v->hiegth);
	v->tab_z = malloc(sizeof(int *) * (v->hiegth));
	v->tab_c = malloc(sizeof(int *) * (v->hiegth));
	if (!v->tab_z || !v->tab_c)
		return;
	s.j = 0;
	s.strs = ft_split_count(s.maps[s.j], ' ', &s.save_x);
	v->width = s.save_x; 
	while (++s.j <= (v->hiegth))
	{
		s.i = -1;
		v->tab_z[s.j - 1] = malloc(sizeof(int) * (v->width)); // allocate sazeof first line 
		v->tab_c[s.j - 1] = malloc(sizeof(int) * (v->width)); // allocate sazeof first line 
		if (!v->tab_z[s.j - 1] || !v->tab_c[s.j - 1])
			return;
		while (++s.i < (v->width))
			put_z_color(s.strs[s.i], &v->tab_z[s.j - 1][s.i], &v->tab_c[s.j - 1][s.i]);
		free_strs(s.strs);
		s.strs = ft_split_count(s.maps[s.j], ' ', &s.save_x);
		if (s.save_x < v->width)
			ft_error("Found wrong line length. Exiting.\n");
	}
	// free_strs(s.maps); ?????
	// system("leaks fdf");
}
