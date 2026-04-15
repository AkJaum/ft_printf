/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjaum <akjaum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:52:36 by jneris-d          #+#    #+#             */
/*   Updated: 2026/04/14 20:56:29 by akjaum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checktype(char message, va_list args)
{
	int	count;

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
