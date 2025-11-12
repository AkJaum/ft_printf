/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:01:16 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/12 16:01:25 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* The ft_puthex function recursively converts an unsigned integer n into its
hexadecimal representation, using either lowercase ('x') or uppercase ('X')
formatting based on the format parameter, and writes the result character by
character while returning the total number of characters printed. It relies on
an external function, ft_putchar, to output individual characters. */
int	ft_puthex(unsigned int n, char format)
{
	char	*hex;
	int		count;

	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	ft_putchar(hex[n % 16]);
	count++;
	return (count);
}
