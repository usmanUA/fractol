/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:36:24 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/04 14:15:12 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_putpixel(t_image *image, int a, int b, int colr)
{
	char	*dest;

	dest = image->pixels + (b * image->line + a * (image->bitspp / 8));
	*(unsigned int *)dest = colr;
}

void	ft_fractal(t_fractol *fractal, t_complex c, int x, int y)
{
	if (fractal->fractal == 1)
		ft_mandelbrot(fractal, c, x, y);
	else if (fractal->fractal == 2)
		ft_juliaset(fractal, c, x, y);
	else if (fractal->fractal == 3)
		ft_mandelbox(fractal, c, x, y);
	else if (fractal->fractal == 4)
		ft_burningship(fractal, c, x, y);
	else if (fractal->fractal == 5)
	{
		fractal->tricorn = 1;
		ft_mandelbrot(fractal, c, x, y);
	}
}

void	ft_render(t_fractol *fractal)
{
	int			x;
	int			y;
	t_complex	c;
	int			ind;

	x = -1;
	ind = 1;
	while (++x < H)
	{
		y = -1;
		while (++y < W)
		{
			c.real = (ft_scale(x, -2, 2, W) * fractal->zoom)
				+ fractal->move_real;
			c.img = (ft_scale(y, -2 + (2 + 2) * H / W, -2, H) * fractal->zoom)
				+ fractal->move_img;
			ft_fractal(fractal, c, x, y);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->image.image, 0, 0);
}
