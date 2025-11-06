#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int    ft_putchar(int c);
int    ft_putstr(char *str);
int     ft_putnbr(int n);

#endif