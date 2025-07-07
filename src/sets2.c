#include "fractol.h"

int	burning_ship(double x, double y)
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
		zi = ft_fabs(2.0 * zr * zi) + y;
		zr = ft_fabs(tmp);
		i++;
	}
	if (i == ITER)
		return (0);
	return (itocolor(i, NULL));
}
