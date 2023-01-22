/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:20:48 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/20 03:09:25 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - 48);
	return (result * sign);
}

int ft_atoi_hexa(char *str)
{
    int result;
    int i;
    int hex;
    char *bas;

    if (!str)
        return 0;
    bas = "0123456789abcdef";
    i = 2;
    result = 0;
    
    while (str[i])
    {
        if (ft_isupper(str[i]))
            hex = ft_strchr_ind(bas, str[i] + 32); 
        else
            hex = ft_strchr_ind(bas, str[i]);
        if ((ft_isupper(str[i]) || ft_islower(str[i])) && hex == 0)// && str[i] != '0')
            break;
        result = (result * 16) + hex;
        i++;
    }
    return (result);
}