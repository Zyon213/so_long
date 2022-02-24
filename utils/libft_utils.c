/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:30:01 by yoyohann          #+#    #+#             */
/*   Updated: 2022/02/23 15:30:04 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int	ft_nbrlen(int n)
{
	int	i;
	int	nb;

	nb = n;
	if (nb < 0)
		nb = -nb;
	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	if (n < 0)
		return (i + 1);
	else
		return (i);
}

void	ft_putnbr(int n)
{
	int		nb;
	char	str[16];
	int		len;

	nb = n;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		exit (1);
	}
	if (nb < 0)
		nb = -nb;
	len = ft_nbrlen(n);
	str[len--] = '\0';
	while (nb != 0)
	{
		str[len--] = (nb % 10) + 48;
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	ft_putstr(str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned int)s1[i] - (unsigned int)s2[i]);
		i++;
	}
	return (0);
}
