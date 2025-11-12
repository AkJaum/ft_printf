/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:52:36 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/12 16:00:35 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checktype(char message, va_list args)
{
	int	count;
	int	i;

	i = 0;
	if (message == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (message == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (message == 'd' || message == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (message == 'u')
		count = ft_putunsigned(va_arg(args, unsigned int));
	else if (message == 'x' || message == 'X')
		count = ft_puthex(va_arg(args, unsigned int), message);
	else if (message == 'p')
		count = ft_putpointer(va_arg(args, unsigned long long));
	else if (message == '%')
		count = ft_putchar('%');
	return (count);
}
/* The ft_printf function is a custom implementation of the standard printf
function in C, which formats and prints data to the standard output. It
processes a format string and a variable number of arguments, handling format
specifiers via the helper function ft_checktype, and returns the total number
of characters printed. */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;

	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed += ft_checktype(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			printed++;
		}
		i++;
	}
	va_end(args);
	return (printed);
}
