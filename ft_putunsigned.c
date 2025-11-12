/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:06:28 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/12 16:08:27 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* The ft_putunsigned function takes an unsigned integer n as input and 
recursively writes its decimal representation to the standard output using the
write system call, returning the total number of characters written. It handles
numbers by breaking them into individual digits and converting them to their
ASCII representation. */
int	ft_putunsigned(unsigned int n)
{
	unsigned long	nbr;
	char			c;
	int				count;

	count = 0;
	nbr = n;
	if (nbr >= 10)
	{
		count += ft_putunsigned(nbr / 10);
		c = (nbr % 10) + '0';
		count += write(1, &c, 1);
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		count += write(1, &c, 1);
	}
	return (count);
}
