/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:16:10 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/04 14:05:15 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_closemlx(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image.image);
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

int	ft_keys(int keysym, t_fractol *fractal)
{
	if (keysym == ESC)
		ft_closemlx(fractal);
	else if (keysym == ARROW_UP)
		fractal->move_img += 1.0 * fractal->zoom;
	else if (keysym == ARROW_DOWN)
		fractal->move_img -= 1.0 * fractal->zoom;
	else if (keysym == ARROW_RIGHT)
		fractal->move_real += 1.0 * fractal->zoom;
	else if (keysym == ARROW_LEFT)
		fractal->move_real -= 1.0 * fractal->zoom;
	else if (keysym == PLUS)
		fractal->iter += 45;
	else if (keysym == MINUS)
		fractal->iter -= 45;
	ft_render(fractal);
	return (0);
}

int	ft_mouse(int button, int real, int img, t_fractol *fractal)
{
	(void)real;
	(void)img;
	if (button == 5)
		fractal->zoom *= 0.95;
	else if (button == 4)
		fractal->zoom *= 1.05;
	ft_render(fractal);
	return (0);
}

int	ft_juliaevents(int x, int y, t_fractol *fractal)
{
	if (x > W || x < 0 || y > H || y < 0)
		return (0);
	if (fractal->fractal == 2)
	{
		fractal->julia.real = (ft_scale(x, -2, 2, W) * fractal->zoom)
			+ fractal->move_real;
		fractal->julia.img = (ft_scale(y, 2, -2, H) * fractal->zoom)
			+ fractal->move_img;
	}
	ft_render(fractal);
	return (0);
}

void	ft_events(t_fractol *fractal)
{
	mlx_hook(fractal->mlx_win, 2, 1L << 0, ft_keys, fractal);
	mlx_hook(fractal->mlx_win, 4, 1L << 2, ft_mouse, fractal);
	mlx_hook(fractal->mlx_win, 17, 1L << 17, ft_closemlx, fractal);
	mlx_hook(fractal->mlx_win, 6, 1L << 6, ft_juliaevents, fractal);
}
