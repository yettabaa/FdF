/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:14:35 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/21 22:44:53 by yettabaa         ###   ########.fr       */
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

int 	**get_data(char **av, int ***tab_color,int *x, int *y)
{
	t_get_data s;

	s.maps = get_next_line(av[1], y);
	s.tabz = malloc(sizeof(int *) * (*y));
	s.tabc = malloc(sizeof(int *) * (*y));
	if (!s.tabz || !s.tabc)
		return(NULL);
	s.j = 0;
	s.strs = ft_split_count(s.maps[s.j], ' ', &s.save_x);
	*x = s.save_x; 
	while (++s.j <= (*y))
	{
		s.i = -1;
		s.tabz[s.j - 1] = malloc(sizeof(int) * (*x)); // allocate sazeof first line 
		s.tabc[s.j - 1] = malloc(sizeof(int) * (*x)); // allocate sazeof first line 
		if (!s.tabz[s.j - 1] || !s.tabc[s.j - 1])
			return(NULL);
		while (++s.i < (*x))
			put_z_color(s.strs[s.i], &s.tabz[s.j - 1][s.i], &s.tabc[s.j - 1][s.i]);
		free_strs(s.strs);
		s.strs = ft_split_count(s.maps[s.j], ' ', &s.save_x);
		if (s.save_x < *x)
			ft_error("Found wrong line length. Exiting.\n");
	}
	// system("leaks fdf");
	return (*tab_color = s.tabc, free_strs(s.maps), s.tabz);
}



