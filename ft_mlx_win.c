/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:25:27 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/07 15:51:36 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_exit(int errno, t_fractol *fractal)
{
	if (!fractal)
		exit(errno);
	if (fractal->image.image)
		mlx_destroy_image(fractal->mlx, fractal->image.image);
	if (fractal->mlx_win)
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	if (fractal->mlx)
		free(fractal->mlx);
	if (fractal)
		free(fractal);
	exit(errno);
}

void	ft_mlx(t_fractol *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		ft_exit(ft_errormsg("Error with the connection to MLX", 1), fractal);
	fractal->mlx_win = mlx_new_window(fractal->mlx, H, W, fractal->win_name);
	if (!fractal->mlx_win)
		ft_exit(ft_errormsg("Error creating MLX window.", 1), fractal);
	fractal->image.image = mlx_new_image(fractal->mlx, H, W);
	if (!fractal->image.image)
		ft_exit(ft_errormsg("Error creating image for display.", 1), fractal);
	fractal->image.pixels = mlx_get_data_addr(fractal->image.image,
			&fractal->image.bitspp, &fractal->image.line,
			&fractal->image.endian);
	ft_events(fractal);
}
