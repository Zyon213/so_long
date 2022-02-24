/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:01:22 by yoyohann          #+#    #+#             */
/*   Updated: 2022/02/23 17:14:58 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_msg(char *msg)
{
	ft_putstr("Error!\n");
	ft_putstr(msg);
	exit (1);
}

void	ft_argv_check(int argc, char **argv)
{
	if (argc != 2)
		error_msg("Invalid number of argument.\n");
	if ((ft_strlen(argv[1]) < 4) || (!ft_strchr(argv[1], '.')))
		error_msg("Invalid argument.\n");
	if (ft_strcmp(ft_strchr(argv[1], '.'), ".ber") != 0)
		error_msg("Invalid file type.\n");
}

void	ft_displaynum(int n)
{
	ft_putnbr(n);
	ft_putchar('\n');
}
