#include "fractol.h"

int	mandelbrot(double x, double y)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	size_t	i;

	i = 0;
	zr = 0;
	zi = 0;
	zr2 = 0;
	zi2 = 0;
	while (zr2 + zi2 <= 4.0 && i < ITER)
	{
		zi = 2.0 * zr * zi + y;
		zr = zr2 - zi2 + x;
		zr2 = zr * zr;
		zi2 = zi * zi;
		i++;
	}
	if (i == ITER)
		return (0);
	return (itocolor(i, NULL));
}

int	quadric_cross(double x, double y)
{
	int	xi;
	int	yi;
	int	level;

	level = 0;
	yi = (int)(((x + 1.0) / 2.0) * WIDTH * 2);
	xi = (int)(((y + 1.0) / 2.0) * HEIGHT * 2);
	while (xi != 0 || yi != 0)
	{
		if ((xi % 3 == 1) ^ (yi % 3 == 1))
			return (0);
		xi /= 3;
		yi /= 3;
		level++;
	}
	return (itocolor(30, NULL));
}

int	julia(double x, double y, double cx, double cy)
{
	double			zr2;
	double			zi2;
	size_t			i;

	i = 0;
	zr2 = x * x;
	zi2 = y * y;
	while (zr2 + zi2 <= 4.0 && i < ITER)
	{
		y = 2.0 * x * y + cy;
		x = zr2 - zi2 + cx;
		zr2 = x * x;
		zi2 = y * y;
		i++;
	}
	if (i == ITER)
		return (0);
	return (itocolor(i, NULL));
}

int	tricorn(double x, double y)
{
	double	zr;
	double	zi;
	double	tmp;
	size_t	i;

	i = 0;
	zr = 0;
	zi = 0;
	while (zr * zr + zi * zi <= 4.0 && i < ITER)
	{
		tmp = zr * zr - zi * zi + x;
		zi = -2.0 * zr * zi + y;
		zr = tmp;
		i++;
	}
	if (i == ITER)
		return (0);
	return (itocolor(i, NULL));
}
