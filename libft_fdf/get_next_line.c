/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:29:36 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/30 22:27:31 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_perror(const char *str)
{
	perror(str);
	exit(1);
}

char	**get_next_line(char *name, int *y)
{
	int			fd;
	long long	size;
	char		*baf;
	char		*stock;
	char		**lines;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_perror(name);
	baf = malloc(BUFFER_SIZE + 1);
	if (!baf)
		return (NULL);
	size = 1;
	stock = NULL;
	while (size > 0)
	{
		size = read(fd, baf, BUFFER_SIZE);
		if (size < 0)
			break ;
		baf[size] = '\0';
		stock = ft_strjoin_gnl(stock, baf);
	}
	lines = ft_split_count(stock, '\n', y);
	return (free(baf), free(stock), lines);
}
