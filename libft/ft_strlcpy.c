/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:35:06 by yoyohann          #+#    #+#             */
/*   Updated: 2022/01/17 23:35:09 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
	{
		i = ft_strlen(src);
		return (i);
	}
	while ((src[i] != '\0') && (i < (n - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	if (src[i] != '\0')
		i = ft_strlen(src);
	return (i);
}
