/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:35:32 by yoyohann          #+#    #+#             */
/*   Updated: 2022/01/17 23:35:35 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *str, char c)
{
	int	i;

	i = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)(&str[i]));
	while (i-- > 0)
	{
		if (str[i] == (char)c)
			return ((char *)(&str[i]));
	}
	return (NULL);
}
