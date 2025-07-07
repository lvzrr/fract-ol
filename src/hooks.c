#include "fractol.h"

int	destroy(t_ftl *ftl)
{
	if (!ftl)
		return (0);
	if (ftl->mlx)
	{
		mlx_destroy_image(ftl->mlx, ftl->data.img);
		if (ftl->w)
			mlx_destroy_window(ftl->mlx, ftl->w);
		mlx_destroy_display(ftl->mlx);
		free(ftl->mlx);
	}
	*ftl = (t_ftl){0};
	exit(EXIT_SUCCESS);
}

void	color(int key, t_ftl *f)
{
	if (key == 114)
		f->data.maps[0] = (f->data.maps[0] + 10) % 255;
	else if (key == 103)
		f->data.maps[1] = (f->data.maps[1] + 10) % 255;
	else if (key == 98)
		f->data.maps[2] = (f->data.maps[2] + 10) % 255;
	(void)itocolor(0, f->data.maps);
}

int	khandle(int key, t_ftl *ftl)
{
	if (!ftl)
		return (0);
	if (key == 114 || key == 103 || key == 98)
		color(key, ftl);
	if (key == 65307)
	{
		destroy(ftl);
		return (0);
	}
	if (key == 99)
		match_viewport(ftl);
	else if (key == 97 || key == 65361 || key == 104)
		ftl->data.sx -= .5 / ftl->data.zoom;
	else if (key == 100 || key == 108 || key == 65363)
		ftl->data.sx += .5 / ftl->data.zoom;
	else if (key == 119 || key == 107 || key == 65362)
		ftl->data.sy -= .5 / ftl->data.zoom;
	else if (key == 106 || key == 115 || key == 65364)
		ftl->data.sy += .5 / ftl->data.zoom;
	else if (key == 102)
		change_ftal(ftl);
	render(ftl, false, true);
	return (0);
}

int	mhandle(int code, int x, int y, t_ftl *f)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = (double)x / WIDTH;
	mouse_y = (double)y / HEIGHT;
	if (code == 4)
	{
		f->data.zoom *= 1.1;
		f->data.sx += (mouse_x - 0.5) / f->data.zoom;
		f->data.sy += (mouse_y - 0.5) / f->data.zoom;
	}
	else if (code == 5)
	{
		f->data.zoom *= 0.9;
		f->data.sx -= (mouse_x - 0.5) / f->data.zoom;
		f->data.sy -= (mouse_y - 0.5) / f->data.zoom;
	}
	render(f, false, true);
	return (0);
}
