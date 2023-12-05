/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:27:50 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/04 14:05:44 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_isvalid(char *val)
{
	while (*val == '-' || *val == '+')
		val++;
	while (*val && *val != '.')
	{
		if (!ft_isdigit(*val))
			return (0);
		val++;
	}
	if (*val == '.')
		val++;
	while (*val)
	{
		if (!ft_isdigit(*val))
			return (0);
		val++;
	}
	return (1);
}

int	ft_validfractal(int argc, char **argv)
{
	if (argc == 2 || argc == 4)
	{
		if (!ft_strncmp(argv[1], "MBT", 3))
			return (1);
		if (!ft_strncmp(argv[1], "JS", 2))
			return (2);
		if (!ft_strncmp(argv[1], "MBX", 3))
			return (3);
		if (!ft_strncmp(argv[1], "BS", 2))
			return (4);
		if (!ft_strncmp(argv[1], "TC", 2))
			return (5);
	}
	return (0);
}

int	ft_errormsg(char *msg, int errno)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putendl_fd("", 2);
	return (errno);
}

void	ft_printerror(void)
{
	ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
	ft_putstr_fd("\t./fractol MBT ==> mandelbrot\n", STDERR_FILENO);
	ft_putstr_fd("\t./fractol MBX ==> mandelbox\n", STDERR_FILENO);
	ft_putstr_fd("\t./fractol JS ==> Julia Set\n", STDERR_FILENO);
	ft_putstr_fd("\t./fractol BP ==> Burning Ship\n", STDERR_FILENO);
	ft_putstr_fd("\t./fractol TC ==> Tricorn\n", STDERR_FILENO);
}
