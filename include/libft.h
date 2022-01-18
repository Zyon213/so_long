/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:31:44 by yoyohann          #+#    #+#             */
/*   Updated: 2022/01/18 01:07:52 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_strrchr(const char *str, char c);
char	*ft_itoa(int num);
char	*ft_strcat(char *dst, char *src);
char	*ft_strdup(char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *str, int start, int end);
size_t	ft_strlcpy(char *dst, const char *src, unsigned int n);
int		ft_strlen(char const *str);
int		ft_nbrlen(int n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_nbrlen(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);

#endif
