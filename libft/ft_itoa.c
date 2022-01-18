/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:32:24 by yoyohann          #+#    #+#             */
/*   Updated: 2022/01/18 03:53:56 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_itoa(int num)
{
	char	*str;
	int		n;
	int		i;

	n = num;
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	i = ft_numlen(n);
	str = malloc(sizeof(char) + i);
	if (!str)
		return (NULL);
	str[i] = '\0';
	--i;
	while (num != 0)
	{
		str[i] = (num % 10) - 48;
		num /= 10;
		i--;
	}
	return (str);
}
