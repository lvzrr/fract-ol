#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "lft.h"
# include <math.h>
# include <stdbool.h>

# ifndef WIDTH
#  define WIDTH 900
# endif

# ifndef HEIGHT
#  define HEIGHT 700
# endif

# ifndef ITER
#  define ITER 100
# endif

# ifndef VIEW_SC
#  define VIEW_SC 2.0
# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		ndn;
	double	zoom;
	double	sx;
	double	sy;
	t_u8	maps[3];
}	t_data;

typedef struct s_coord
{
	int		x;
	int		y;
	double	inv_w;
	double	inv_h;
}	t_coord;

typedef enum e_sets
{
	MANDEL,
	JULIA,
	CROSS,
	TRICO,
	SHIP,
}	t_set;

typedef struct s_ftl
{
	t_data	data;
	void	*mlx;
	void	*w;
	t_set	set;
	double	x1;
	double	x2;
}	t_ftl;

void	putln(t_data *d, t_u8 *px);
t_ftl	fetch_data(void *mlx);
void	render(t_ftl *ftl, bool center, bool flush);
int		get_precomp(size_t i, t_u8 flag);
int		mandelbrot(double x, double y);
int		itocolor(size_t i, t_u8 *maps);
int		quadric_cross(double x, double y);
int		julia(double x, double y, double x1, double x2);
int		tricorn(double x, double y);
void	*get_fn(t_set set);
int		destroy(t_ftl *ftl);
int		khandle(int key, t_ftl *ftl);
void	parse_args(int argc, char **argv, t_ftl *ftl);
void	err(t_ftl *ftl, char *a);
int		burning_ship(double x, double y);
int		mhandle(int code, int x, int y, t_ftl *f);
void	change_ftal(t_ftl *ftl);
void	match_viewport(t_ftl *f);
void	phelp(void);
#endif
