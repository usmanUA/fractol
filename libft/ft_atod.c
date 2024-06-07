/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:33:57 by uahmed            #+#    #+#             */
/*   Updated: 2023/11/23 19:34:41 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *str)
{
	long	ints;
	double	fracs;
	double	frac;
	int		sign;

	ints = 0;
	fracs = 0;
	frac = 1;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (*str && *str != '.')
		ints = ints * 10 + (*str++ - '0');
	while (*(++str))
	{
		frac /= 10;
		fracs += (*str - '0') * frac;
	}
	return (sign * (ints + fracs));
}
