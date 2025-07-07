#include "cstr.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	src_len;
	size_t	bytes_to_copy;

	if (!src || n == 0 || !dest)
		return (0);
	src_len = ft_strlen(src);
	if (src_len < (n - 1))
		bytes_to_copy = src_len;
	else
		bytes_to_copy = n - 1;
	ft_memcpy(dest, src, bytes_to_copy + 1);
	dest[bytes_to_copy] = '\0';
	return (src_len);
}
