#ifndef MATH_H
# define MATH_H

# include "mem.h"

typedef union u_fp
{
	double	f;
	t_u64	i;
}	t_fp;

float			ft_q_sqrt(float x);
float			ft_q_sqrt_round(float number, t_u8 n);
float			ft_q_sqrt_fround(float number);
float			ft_roundf(float x, t_u8 n);
float			ft_floorf(float x);
float			ft_ceilf(float x);
t_u128			ft_pow_u128(t_u128 x, t_u128 n);
t_u64			ft_pow_u64(t_u64 x, t_u64 n);
t_u32			ft_pow_u32(t_u32 x, t_u32 n);
t_u8			ft_pow_u8(t_u8 x, t_u8 n);
int				ft_ipow(int x, t_u64 n);
long long		ft_lpow(long long x, t_u64 n);
float			ft_fpow(float x, t_u64 n);
double			ft_dpow(double x, t_u64 n);
float			ft_roundff(float x);
double			ft_fabs(double x);
#endif
