#include "io.h"

t_string	get_next_line(int fd)
{
	char			c;
	static t_string	out;
	t_string		tmp;

	if (fd < 0)
		return ((t_string){0});
	if (!out.alloc_size)
	{
		out = ft_tstr_new(BUFSIZE);
		if (!out.data)
			return ((t_string){0});
	}
	c = ft_fgetc(fd);
	while (c != EOF && c != '\n')
	{
		ft_tstr_push(&out, c);
		c = ft_fgetc(fd);
	}
	if (c == '\n')
		ft_tstr_push(&out, c);
	if (c == EOF)
		return (ft_tstr_free(&out), (t_string){0});
	tmp = ft_tstr_clone(&out);
	return (ft_tstr_clear(&out), tmp);
}
