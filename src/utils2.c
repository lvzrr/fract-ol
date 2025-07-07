#include "fractol.h"

inline void	phelp(void)
{
	ft_fprintf(2, "Usage: ./fract-ol [SET] [OPTS]\n"
		" - SETS: mandelbrot, julia, cross, tricorn\n"
		" - OPTS: in julia, you can use julia <f> <f> for new sets\n");
}

void	err(t_ftl *ftl, char *a)
{
	ft_fprintf(2, "Unrecognised command: %s\n", a);
	phelp();
	destroy(ftl);
	exit(1);
}

t_u8	parse_extras(int argc, char **argv, t_ftl *ftl, int *offs)
{
	while (*offs < argc)
	{
		if (!ft_strcmp(argv[*offs], "tricorn"))
			ftl->set = TRICO;
		else if (!ft_strcmp(argv[*offs], "ship"))
			ftl->set = SHIP;
		else
			return (0);
		(*offs)++;
	}
	return (1);
}

void	parse_args(int argc, char **argv, t_ftl *ftl)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "mandelbrot"))
			ftl->set = MANDEL;
		else if (!ft_strcmp(argv[i], "julia"))
		{
			ftl->set = JULIA;
			if (i + 2 < argc)
			{
				ftl->x1 = ft_atod(argv[++i]);
				ftl->x2 = ft_atod(argv[++i]);
				i++;
				continue ;
			}
		}
		else if (!ft_strcmp(argv[i], "cross"))
			ftl->set = CROSS;
		else
			if (!parse_extras(argc, argv, ftl, &i))
				err(ftl, argv[i]);
		i++;
	}
}
