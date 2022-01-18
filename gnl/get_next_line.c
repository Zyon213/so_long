/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:26:29 by yoyohann          #+#    #+#             */
/*   Updated: 2022/01/17 23:26:37 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] != '\n')
		i++;
	line = malloc(sizeof(char) + i);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_extra_line(char *str)
{
	int		i;
	int		j;
	char	*ex_line;

	i = 0;
	while (str[i] != '\n')
		i++;
	ex_line = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!ex_line)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		ex_line[j++] = str[i++];
	ex_line[j] = '\0';
	return (ex_line);
}

int	get_next_line(int fd, char **line)
{
	int			byte;
	char		*buff;
	static char	*store;

	byte = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (store == NULL)
		store = ft_strdup("");
	while (byte > 0 && !ft_strchr(store, '\n'))
	{
		byte = read(fd, buff, BUFFER_SIZE);
		buff[byte] = '\0';
		store = ft_strjoin(store, buff);
	}	
	if (ft_strchr(store, '\n'))
	{
		*line = ft_get_line(store);
		store = ft_get_extra_line(store);
	}
	if (byte == 0)
	{
		*line = ft_strdup(store);
		return (0);
	}
	return (byte);
}
