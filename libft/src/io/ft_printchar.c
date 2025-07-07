#include "lft.h"

int	ft_printchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
