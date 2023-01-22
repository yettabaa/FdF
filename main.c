#include <stdio.h>
#include <math.h>
#include "fdf.h"

// int trma(float x) {
//     return round((x - (int)x)*1000);
// }
// int ft_atoi_hexa(char *str)
// {
//     int result;
//     int i;
//     int hex;
//     char *bas;

//     bas = "0123456789abcdef";
//     i = 2;
//     result = 0;
    
//     while (str[i])
//     {
//         if (ft_isupper(str[i]))
//             hex = ft_strchr_ind(bas, str[i] + 32);
//         else
//             hex = ft_strchr_ind(bas, str[i]);
//         if ((ft_isupper(str[i]) || ft_islower(str[i])) && hex == 0 && str[i] != '0')
//             break;
//         result = (result * 16) + hex;
//         i++;
//     }
//     return (result);
// }
int main()
{



    // printf("%d\n", ft_atoi_hexa("0xsFFsFFFF"));

    printf("%d\n", fmaxl(5,3));
    
    
    // printf("%d\n", ft_strchr_ind(str, 0 + 48));
    // printf("hexa = %x", 5555);
}