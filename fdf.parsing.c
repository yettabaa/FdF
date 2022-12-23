/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:14:35 by yettabaa          #+#    #+#             */
/*   Updated: 2022/12/23 03:41:26 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(const char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int	count_x(char const *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		while ((*s == 32 || *s == '\n') && *s) // should skip space or \n
			s++;
		if (*s != 32 && *s != '\n' && *s)
		{
			while (*s != 32 && *s != '\n' && *s)
			// should skip no space and no \n
				s++;
			i++;
		}
	}
	return (i);
}

char	**gnl_maps_xy(char *name, int *x, int *y)
{
	int		fd;
	char	*read;
	char	*tmp;
	char	**lines;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		perror("");
	*y = 0;
	tmp = NULL;
	read = get_next_line(fd);
	*x = count_x(read);
	while (read)
	{
		if (*x > count_x(read) && read)
			ft_error("Found wrong line length. Exiting.\n");
		tmp = ft_strjoin(tmp, read);
		free(read);
		read = get_next_line(fd);
		(*y)++;
	}
	lines = ft_split(tmp, '\n');
	free(tmp);
	return (lines);
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
