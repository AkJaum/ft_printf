/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:01:37 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/12 16:02:59 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* The ft_putnbr function takes an integer n as input and recursively writes its
decimal representation to the standard output, including handling negative
numbers by writing a leading -. It returns the total number of characters
written, using the write system call for output. */
int	ft_putnbr(int n)
{
	char	c;
	long	nbr;
	int		count;

	count = 0;
	nbr = n;
	if (n < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}
