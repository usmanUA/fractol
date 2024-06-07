/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:50:34 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/07 15:50:03 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

//********** Header Inclusion **********//
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

//********** Struct Definitions **********//
typedef struct s_complex
{
	double		real;
	double		img;
}				t_complex;

typedef struct s_image
{
	void		*image;
	char		*pixels;
	int			bitspp;
	int			endian;
	int			line;
}				t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*mlx_win;
	char		*win_name;
	t_complex	julia;
	int			fractal;
	double		zoom;
	int			iter;
	double		move_real;
	double		move_img;
	int			tricorn;
	t_image		image;
}				t_fractol;

//********** MACRO Definitions **********//
# define ERROR_MSG "Usage:\n"
# define IVALID_VAL_MSG "Number:\n\nreal: <num{.num}>\nimaginary: <num{.num}>\n"
# define H 800
# define W 800
# define F 1
# define S 2
# define R 0.5
# define THRESH 4

# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define PSYCHEDELIC_CRIMSON_ADDRESS 0xDC143C

# define ESC 53
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 124
# define ARROW_RIGHT 123
# define PLUS 69
# define MINUS 78

//********** Function Prototypes **********//
int				ft_closemlx(t_fractol *fractal);
void			ft_render(t_fractol *fractal);
void			ft_putpixel(t_image *image, int a, int b, int colr);
void			ft_events(t_fractol *fractal);
int				ft_juliaevents(int x, int y, t_fractol *fractal);
int				ft_mouse(int button, int real, int img, t_fractol *fractal);
int				ft_keys(int keysym, t_fractol *fractal);
void			ft_mlx(t_fractol *fractal);
t_complex		ft_mandelbrotfunc(t_fractol *fractal, t_complex z, t_complex c,
					int burn);
int				ft_validfractal(int argc, char **argv);
int				ft_isvalid(char *val);
void			ft_fractol(char *win_name, double real, double img, int fract);
double			ft_boxfold(double v);
double			ft_ballfold(double m);
void			ft_fractal(t_fractol *fractal, t_complex c, int x, int y);
double			ft_scale(double orig, double new_min, double new_max,
					double old_max);
void			ft_mandelbrot(t_fractol *fractal, t_complex c, int x, int y);
void			ft_juliaset(t_fractol *fractal, t_complex c, int x, int y);
void			ft_mandelbox(t_fractol *fractal, t_complex c, int x, int y);
void			ft_burningship(t_fractol *fractal, t_complex c, int x, int y);
void			ft_printerror(void);
int				ft_errormsg(char *msg, int errno);
void			ft_mlximage(t_fractol *fractal);

#endif