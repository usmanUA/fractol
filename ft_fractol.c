/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:52:54 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/07 16:01:06 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_fractol(char *win_name, double real, double img, int fract)
{
	t_fractol	*fractal;

	fractal = malloc(sizeof(t_fractol));
	fractal->win_name = win_name;
	fractal->fractal = fract;
	fractal->move_real = 0.0;
	fractal->move_img = 0.0;
	fractal->iter = 50;
	fractal->julia.real = real;
	fractal->julia.img = img;
	fractal->zoom = 1.0;
	fractal->tricorn = 0;
	ft_mlx(fractal);
	ft_render(fractal);
	mlx_loop(fractal->mlx);
}

int	main(int argc, char *argv[])
{
	int	fractal;

	fractal = ft_validfractal(argc, argv);
	if (fractal)
	{
		if (fractal == 2)
		{
			if (argc < 4 || !ft_isvalid(argv[2]) || !ft_isvalid(argv[3]))
			{
				ft_putstr_fd(IVALID_VAL_MSG, STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
			else
				ft_fractol(argv[1], ft_atod(argv[2]), ft_atod(argv[3]),
					fractal);
		}
		else
			ft_fractol(argv[1], 0.0, 0.0, fractal);
	}
	else
	{
		ft_printerror();
		exit(EXIT_FAILURE);
	}
}
