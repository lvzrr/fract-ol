#include "math.h"

int	ft_ipow(int x, t_u64 n)
{
	int	res;

	res = 1;
	while (n)
	{
		if ((n & 1) == 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return (res);
}

long long	ft_lpow(long long x, t_u64 n)
{
	long long	res;

	res = 1;
	while (n)
	{
		if ((n & 1) == 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return (res);
}

float	ft_fpow(float x, t_u64 n)
{
	float	res;

	res = 1;
	while (n)
	{
		if ((n & 1) == 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return (res);
}

double	ft_dpow(double x, t_u64 n)
{
	double	res;

	res = 1.0;
	while (n)
	{
		if ((n & 1) == 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return (res);
}
