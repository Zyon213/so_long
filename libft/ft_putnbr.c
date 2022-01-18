/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 03:56:03 by yoyohann          #+#    #+#             */
/*   Updated: 2022/01/18 03:56:09 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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
