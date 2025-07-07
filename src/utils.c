#include "fractol.h"

t_ftl	fetch_data(void *mlx)
{
	t_ftl	ftl;

	ftl = (t_ftl){0};
	if (!mlx)
		return ((t_ftl){0});
	ftl.data.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	ftl.mlx = mlx;
	ftl.data.addr = mlx_get_data_addr(ftl.data.img,
			&ftl.data.bpp, &ftl.data.ll, &ftl.data.ndn);
	ftl.data.zoom = 1.0;
	ftl.data.sx = 0.0;
	ftl.data.sy = 0.0;
	ftl.set = MANDEL;
	ftl.data.maps[0] = 3;
	ftl.data.maps[1] = 1;
	ftl.data.maps[2] = 7;
	(void)itocolor(0, ftl.data.maps);
	ftl.x1 = 0.231;
	ftl.x2 = -0.7;
	return (ftl);
}

int	itocolor(size_t i, t_u8 *m)
{
	t_u32		r;
	t_u32		g;
	t_u32		b;
	t_u32		tmp;
	static t_u8	map[3];

	if (m)
		ft_memcpy(map, m, 3 * sizeof(t_u8));
	tmp = i * map[0];
	r = tmp | ((255 - tmp) >> 31);
	tmp = i * map[1];
	g = tmp | ((255 - tmp) >> 31);
	tmp = i * map[2];
	b = tmp | ((255 - tmp) >> 31);
	return (b | g << 8 | r << 16 | 1 << 24);
}

void	*get_fn(t_set set)
{
	if (set == MANDEL)
		return (mandelbrot);
	else if (set == CROSS)
		return (quadric_cross);
	else if (set == TRICO)
		return (tricorn);
	else if (set == SHIP)
		return (burning_ship);
	return (NULL);
}
