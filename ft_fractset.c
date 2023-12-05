/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:18:00 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/04 15:04:17 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_mandelbrot(t_fractol *fractal, t_complex c, int x, int y)
{
	int			ind;
	t_complex	z;
	double		color;

	ind = 0;
	z.real = 0.0;
	z.img = 0.0;
	while (ind < fractal->iter)
	{
		z = ft_mandelbrotfunc(fractal, z, c, 0);
		if ((z.real * z.real + z.img * z.img) > THRESH)
		{
			color = ft_scale(ind, BLACK, WHITE, fractal->iter);
			ft_putpixel(&fractal->image, x, y, color);
			return ;
		}
		ind++;
	}
	ft_putpixel(&fractal->image, x, y, PSYCHEDELIC_CRIMSON_ADDRESS);
}

void	ft_juliaset(t_fractol *fractal, t_complex z, int x, int y)
{
	int			ind;
	t_complex	c;
	double		color;

	ind = 0;
	c.real = fractal->julia.real;
	c.img = fractal->julia.img;
	while (ind < fractal->iter)
	{
		z = ft_mandelbrotfunc(fractal, z, c, 0);
		if ((z.real * z.real + z.img * z.img) > THRESH)
		{
			color = ft_scale(ind, BLACK, WHITE, fractal->iter);
			ft_putpixel(&fractal->image, x, y, color);
			return ;
		}
		ind++;
	}
	ft_putpixel(&fractal->image, x, y, PSYCHEDELIC_CRIMSON_ADDRESS);
}

void	ft_mandelbox(t_fractol *fractal, t_complex c, int x, int y)
{
	int			ind;
	t_complex	z;
	double		magnitude;
	double		color;

	ind = 0;
	z.real = c.real;
	z.img = c.img;
	while (ind < fractal->iter)
	{
		z.real = F * ft_boxfold(z.real);
		z.img = F * ft_boxfold(z.img);
		magnitude = sqrt(z.real * z.real + z.img * z.img);
		z.real = z.real * S * ft_ballfold(magnitude) + c.real;
		z.real = z.real * S * ft_ballfold(magnitude) + c.img;
		if ((sqrt(magnitude)) > 2)
		{
			color = ft_scale(ind, BLACK, WHITE, fractal->iter);
			ft_putpixel(&fractal->image, x, y, color);
			return ;
		}
		ind++;
	}
	ft_putpixel(&fractal->image, x, y, PSYCHEDELIC_CRIMSON_ADDRESS);
}

void	ft_burningship(t_fractol *fractal, t_complex c, int x, int y)
{
	int			ind;
	t_complex	z;
	double		color;

	z.real = 0.0;
	z.img = 0.0;
	ind = 0;
	while (ind < fractal->iter)
	{
		z = ft_mandelbrotfunc(fractal, z, c, 1);
		if ((z.real * z.real + z.img * z.img) > THRESH)
		{
			color = ft_scale(ind, BLACK, WHITE, fractal->iter);
			ft_putpixel(&fractal->image, x, y, color);
			return ;
		}
		ind++;
	}
	ft_putpixel(&fractal->image, x, y, PSYCHEDELIC_CRIMSON_ADDRESS);
}
