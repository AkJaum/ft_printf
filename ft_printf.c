/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:53:26 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/05 14:54:52 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void ft_checktype(char message, va_list args, int count)
{
    if (message == 'c')
        count += ft_putchar(va_arg(args, int));
    else if (message == 's')
        count += ft_putstr(va_arg(args, char *));
    else if (message == 'd' || message == 'i')
        count += ft_putnbr(va_arg(args, int));
    else if (message == 'u')
        count += ft_putunsigned(va_arg(args, unsigned int));
    else if (message == 'x' || message == 'X')
        count += ft_puthex(va_arg(args, unsigned int), message);
    else if (message == 'p')
        count += ft_putpointer(va_arg(args, unsigned long long));
    else if (message == '%')
        count += ft_putchar('%');
}

int ft_printf(const char *format, ...)
{
    int count;
    int i;
    
    count = 0;
    i = 0;
	va_list args;
    va_start(args, format);
    while (format[count])
    {
        if (format[count] == '%')
        {
            count++;
            ft_checktype(format[count], args, count);
            count++;
            i += 2;
        }
        write(1, &format[count], 1);
        count++;
    }
    va_end(args);
    printf("%d", count - i);
    return (count - i);
}
