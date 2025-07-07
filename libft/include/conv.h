#ifndef CONV_H
# define CONV_H
# include <unistd.h>
# include <stdlib.h>

int				ft_atoi(const char *str);
ssize_t			ft_atol(const char *str);
float			ft_atof(const char *s);
double			ft_atod(const char *s);
int				ft_atoi_base(char *str, char *base, int base_len);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, char *base);
char			*ft_utoa_base(size_t n, char *base);
#endif
