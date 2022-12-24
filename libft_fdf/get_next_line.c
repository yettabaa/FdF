/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:29:36 by yettabaa          #+#    #+#             */
/*   Updated: 2022/12/23 18:42:53 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**get_next_line(char *name, int *y)
{
	int 		fd;
	long long 	size;
	char		*baf;
	char		*stock;
	char		**lines;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		perror("");
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
	return (free(baf) ,free(stock), lines);
}
