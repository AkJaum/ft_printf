/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:00:50 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/12 16:01:03 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* The ft_putchar function writes a single character, represented by the integer
c, to the standard output (file descriptor 1) using the write system call and
returns the value 1, indicating that one character was written. */
int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
