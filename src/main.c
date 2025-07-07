#include "fractol.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	t_ftl	ftl;

	(void)argc;
	(void)argv;
	if (argc == 1)
		return (phelp(), 0);
	mlx = mlx_init();
	ftl = fetch_data(mlx);
	parse_args(argc, argv, &ftl);
	render(&ftl, true, false);
	ftl.w = mlx_new_window(mlx, WIDTH, HEIGHT, "fract-ol");
	mlx_put_image_to_window(mlx, ftl.w, ftl.data.img, 0, 0);
	mlx_key_hook(ftl.w, khandle, &ftl);
	mlx_mouse_hook(ftl.w, mhandle, &ftl);
	mlx_hook(ftl.w, 17, 0, destroy, &ftl);
	mlx_loop(mlx);
	return (0);
}
