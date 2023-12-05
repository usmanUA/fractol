/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:19:30 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/04 12:48:16 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

double	ft_scale(double orig, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (orig - 0) / (old_max - 0) + new_min);
}

t_complex	ft_mandelbrotfunc(t_fractol *fractal, t_complex z, t_complex c,
		int burn)
{
	t_complex	new_z;
	t_complex	res;
	int			two;

	two = 2;
	if (burn)
	{
		z.real = fabs(z.real);
		z.img = fabs(z.img);
	}
	new_z.real = (z.real * z.real - z.img * z.img);
	if (fractal->tricorn)
		two *= -1;
	new_z.img = two * z.real * z.img;
	res.real = new_z.real + c.real;
	res.img = new_z.img + c.img;
	return (res);
}

double	ft_boxfold(double v)
{
	if (v > 1)
		v = 2 - v;
	else if (v < -1)
		v = -2 - v;
	return (v);
}

double	ft_ballfold(double magnitude)
{
	if (magnitude < R)
		magnitude = magnitude / (R * R);
	else if (magnitude < 1)
		magnitude = 1 / (magnitude * magnitude);
	return (magnitude);
}
