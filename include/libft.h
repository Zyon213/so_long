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

char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_nbrlen(int n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_nbrlen(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
char	**ft_split(char *s, char c);

#endif
