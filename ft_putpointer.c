/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:03:27 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/19 11:40:56 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* The ft_puthexptr function recursively converts an unsigned long long integer
to its hexadecimal representation using lowercase letters and prints it
character by character. It returns the total number of characters printed. */
int	ft_puthexptr(unsigned long long n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthexptr(n / 16);
	ft_putchar(hex[n % 16]);
	count++;
	return (count);
}

int	ft_putpointer(unsigned long long ptr)
{
	char	*hex;
	int		count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	hex = "0123456789abcdef";
	count = ft_putstr("0x");
	if (ptr == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	if (ptr >= 16)
		count += ft_puthexptr(ptr / 16);
	ft_putchar(hex[ptr % 16]);
	count++;
	return (count);
}
