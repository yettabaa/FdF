/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:29:36 by yettabaa          #+#    #+#             */
/*   Updated: 2022/12/23 15:48:45 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	len_new(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static	char	*stop_at_nel(char *stock)
{
	char	*gnl;

	if (!stock)
		return (free(stock), NULL);
	if (stock[0] == '\0')
		return (NULL);
	if (ft_strchr(stock, '\n'))
	{
		gnl = ft_substr(stock, 0, len_new(stock) + 1);
		return (gnl);
	}
	return (stock);
}

static	char	*stock_str(char *stock)
{
	char	*new_s;
	
	if (!stock || (stock[0] == '\0'))
		return (free(stock), NULL);
	if (ft_strchr(stock, '\n'))
	{
		new_s = ft_strdup(ft_strchr(stock, '\n') + 1);
		free(stock);
		stock = NULL;
		return (new_s);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	long			t;
	char		*gnl;
	char *buf; 
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return NULL;
	t = 1;
	while (t > 0 && !ft_strchr(stock, '\n'))
	{
		t = read(fd, buf, BUFFER_SIZE);
		if (t < 0)
			return(free(stock), stock = NULL, free(buf), NULL);
		buf[t] = '\0';
		stock = ft_strjoin_gnl(stock, buf);
	}
	gnl = stop_at_nel(stock);
	stock = stock_str(stock);
	return (free(buf), gnl);
}
