#include "fractol.h"

void	change_ftal(t_ftl *ftl)
{
	ftl->set = (ftl->set + 1) % 5;
	ftl->data.zoom = 1.0;
	ftl->data.sx = 0.0;
	ftl->data.sy = 0.0;
	render(ftl, true, true);
}
