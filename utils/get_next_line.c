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
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_extra_line(char *str)
{
	int		i;
	int		j;
	char	*ex_line;

	i = 0;
	j = 0;
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	ex_line = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!ex_line)
		return (NULL);
	while (str[i] != '\0')
		ex_line[j++] = str[i++];
	ex_line[j] = '\0';
	free(str);
	return (ex_line);
}

char	*ft_read_file(int fd, char *line)
{
	int			byte;
	char		*buff;

	byte = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (byte != 0 && !ft_strchr(line, '\n'))
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte] = '\0';
		line = ft_strjoin(line, buff);
	}	
	free(buff);
	return (line);
}

char	*ft_get_next_line(int fd)
{
	static char	*store;
	char		*line;

	if (fd < 0)
		return (NULL);
	store = ft_read_file(fd, store);
	if (!store)
		return (NULL);
	line = ft_get_line(store);
	store = ft_get_extra_line(store);
	return (line);
}
