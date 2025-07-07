#include "fractol.h"

static inline void	batch(int *line, t_coord *c,
						int (*f)(double x, double y), t_data *d)
{
	double	yv;

	yv = c->y * c->inv_h + d->sy;
	while (c->x + 4 < WIDTH)
	{
		line[c->x] = f(c->x * c->inv_w + d->sx, yv);
		(c->x)++;
		line[c->x] = f(c->x * c->inv_w + d->sx, yv);
		(c->x)++;
		line[c->x] = f(c->x * c->inv_w + d->sx, yv);
		(c->x)++;
		line[c->x] = f(c->x * c->inv_w + d->sx, yv);
		(c->x)++;
	}
	while (c->x < WIDTH)
	{
		line[c->x] = f(c->x * c->inv_w + d->sx, yv);
		(c->x)++;
	}
}

static inline void	batch_extra(int *line, t_coord *c,
						int (*f)(double x, double y, double x1, double x2),
						t_ftl *ftl)
{
	double	yv;

	yv = c->y * c->inv_h + ftl->data.sy;
	while (c->x + 4 < WIDTH)
	{
		line[c->x] = f(c->x * c->inv_w + ftl->data.sx, yv, ftl->x1, ftl->x2);
		(c->x)++;
		line[c->x] = f(c->x * c->inv_w + ftl->data.sx, yv, ftl->x1, ftl->x2);
		(c->x)++;
		line[c->x] = f(c->x * c->inv_w + ftl->data.sx, yv, ftl->x1, ftl->x2);
		(c->x)++;
		line[c->x] = f(c->x * c->inv_w + ftl->data.sx, yv, ftl->x1, ftl->x2);
		(c->x)++;
	}
	while (c->x < WIDTH)
	{
		line[c->x] = f(c->x * c->inv_w + ftl->data.sx, yv, ftl->x1, ftl->x2);
		(c->x)++;
	}
}

inline void	match_viewport(t_ftl *f)
{
	if (f->set == MANDEL)
	{
		f->data.sx = -2.0;
		f->data.sy = -1.0;
	}
	else if (f->set == CROSS || f->set == JULIA
		|| f->set == TRICO)
	{
		f->data.sx = -1.0;
		f->data.sy = -1.0;
	}
	else if (f->set == SHIP)
	{
		f->data.sx = -1.5;
		f->data.sy = -1.5;
	}
	f->data.zoom = 1.0;
}

void	render(t_ftl *ftl, bool center, bool flush)
{
	int		*line;
	t_coord	c;

	if (!ftl)
		return ;
	c = (t_coord){0};
	c.inv_h = VIEW_SC * (1.0 / HEIGHT) / ftl->data.zoom;
	c.inv_w = VIEW_SC * (1.0 / WIDTH) / ftl->data.zoom;
	if (center)
		match_viewport(ftl);
	while (c.y < HEIGHT)
	{
		c.x = 0;
		line = (int *)(ftl->data.addr + c.y * ftl->data.ll);
		if (ftl->set == JULIA)
			batch_extra(line, &c, julia, ftl);
		else
			batch(line, &c,
				(int (*)(double, double))get_fn(ftl->set), &ftl->data);
		c.y++;
	}
	if (flush)
		mlx_put_image_to_window(ftl->mlx, ftl->w, ftl->data.img, 0, 0);
}
