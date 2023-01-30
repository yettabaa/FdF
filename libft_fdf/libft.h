/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:18:32 by yettabaa          #+#    #+#             */
/*   Updated: 2023/01/30 22:27:45 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2147483646
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_perror(const char *str);
int		ft_isalpha(int arg);
int		ft_isupper(int arg);
int		ft_islower(int arg);
int		ft_isdigit(int arg);
int		ft_isalnum(int arg);
int		ft_isascii(int arg);
int		ft_isprint(int arg);
size_t	ft_strlen(const char *str);
int		ft_tolower(int arg);
int		ft_toupper(int arg);
char	*ft_strchr(const char *str, int c);
int		ft_strchr_ind(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *str);
int		ft_atoi_hexa(char *str);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strjoin_c(char const *s1, char const *s2, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split_count(char const *s, char c, int *nb);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**get_next_line(char *name, int *y);

#endif