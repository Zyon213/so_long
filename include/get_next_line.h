/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:31:33 by yoyohann          #+#    #+#             */
/*   Updated: 2022/02/23 16:21:12 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

int		ft_strlen(char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_extra_line(char *str);
char	*ft_get_line(char *str);
char	*ft_read_file(int fd, char *line);
char	*ft_get_next_line(int fd);

#endif
