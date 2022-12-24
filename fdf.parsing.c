/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:14:35 by yettabaa          #+#    #+#             */
/*   Updated: 2022/12/24 21:19:28 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	free_tab(int **tab, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	cheker_z(char *str, int *tab_z, int *tab_color)
{

	char	**spl_vrg;
	
	spl_vrg = ft_split(str, ',');
	*tab_z = ft_atoi(spl_vrg[0]);
	if (!spl_vrg[1] && !ft_strchr(str, ','))
		*tab_color = 16777215;
	else if (!ft_strncmp(spl_vrg[1], "0x", 2) || !ft_strncmp(spl_vrg[1], "0X",2))
		*tab_color = ft_atoi_hexa(spl_vrg[1]);
	else
		*tab_color = ft_atoi(spl_vrg[1]);
	free_strs(spl_vrg);
}

void 	get_z_coordinates(char *name, int ***tab_z, int ***tab_color,int *x, int *y)
{
	int		**tabz;
	int		**tabc;
	char	**strs;
	char	**maps;
	int		save_x;
	int		i;
	int		j;

	maps = get_next_line(name, y);
	tabz = malloc(sizeof(int *) * (*y));
	tabc = malloc(sizeof(int *) * (*y));
	if (!tabz || !tabc)
		return ;
	j = 0;
	strs = ft_split_count(maps[j], ' ', &save_x);
	*x = save_x; 
	while (++j <= (*y))
	{
		i = -1;
		tabz[j - 1] = malloc(sizeof(int) * (*x)); // allocate sazeof first line 
		tabc[j - 1] = malloc(sizeof(int) * (*x)); // allocate sazeof first line 
		if (!tabz[j - 1] || !tabc[j - 1])
			return ;
		while (++i < (*x))
			cheker_z(strs[i], &tabz[j - 1][i], &tabc[j - 1][i]);
		strs = ft_split_count(maps[j], ' ', &save_x);
		if (save_x < *x)
			ft_error("Found wrong line length. Exiting.\n");
	}
	*tab_color = tabc;
	*tab_z = tabz;
	free_strs(maps);
	// system("leaks fdf");
}

void print_strs(char **s)
{
    int d = 0;
    while (s[d])
        printf("%s\n", s[d++]);
}


