#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int    ft_putchar(int c);
int    ft_putstr(char *str);
int     ft_putnbr(int n);
int ft_putunsigned(unsigned int n);
int ft_puthex(unsigned int n, char format);

#endif