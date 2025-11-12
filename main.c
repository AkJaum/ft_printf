/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tester42 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 00:00:00 by tester42          #+#    #+#             */
/*   Updated: 2025/11/07 00:00:00 by tester42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char			c;
	char			*s;
	int				d;
	int				i;
	unsigned int	u;
	void			*p;

	c = 'A';
	s = "Hello 42!";
	d = -42;
	i = 2147483647;
	u = 4294967295;
	p = s;

	printf("=== TESTES %%c ===\n");
	ft_printf("ft: [%c]\n", c);
	printf("og: [%c]\n\n", c);

	printf("=== TESTES %%s ===\n");
	ft_printf("ft: [%s]\n", s);
	printf("og: [%s]\n", s);
	ft_printf("ft: [%s]\n", (char *)NULL);
	printf("og: [%s]\n\n", (char *)NULL);

	printf("=== TESTES %%p ===\n");
	ft_printf("ft: [%p]\n", p);
	printf("og: [%p]\n", p);
	ft_printf("ft: [%p]\n", (void *)NULL);
	printf("og: [%p]\n\n", (void *)NULL);

	printf("=== TESTES %%d / %%i ===\n");
	ft_printf("ft: [%d]\n", d);
	printf("og: [%d]\n", d);
	ft_printf("ft: [%i]\n", i);
	printf("og: [%i]\n", i);
	ft_printf("ft: [%d]\n", INT_MIN);
	printf("og: [%d]\n", INT_MIN);
	ft_printf("ft: [%d]\n", INT_MAX);
	printf("og: [%d]\n\n", INT_MAX);

	printf("=== TESTES %%u ===\n");
	ft_printf("ft: [%u]\n", u);
	printf("og: [%u]\n", u);
	ft_printf("ft: [%u]\n", 0);
	printf("og: [%u]\n", 0);
	ft_printf("ft: [%u]\n", -1);
	printf("og: [%u]\n\n", -1);

	printf("=== TESTES %%x / %%X ===\n");
	ft_printf("ft: [%x]\n", 255);
	printf("og: [%x]\n", 255);
	ft_printf("ft: [%X]\n", 255);
	printf("og: [%X]\n", 255);
	ft_printf("ft: [%x]\n", 0);
	printf("og: [%x]\n", 0);
	ft_printf("ft: [%x]\n", 4294967295u);
	printf("og: [%x]\n\n", 4294967295u);

	printf("=== TESTES %% (porcentagem literal) ===\n");
	ft_printf("ft: [%%%%]\n");
	printf("og: [%%%%]\n");
	ft_printf("ft: [%%c %%s %%d %%u %%x]\n", 'Z', "Mix", 42, 42u, 42u);
	printf("og: [%%c %%s %%d %%u %%x]\n", 'Z', "Mix", 42, 42u, 42u);

	printf("\n=== TESTES MISTOS ===\n");
	ft_printf("ft: char=%c, str=%s, int=%d, hex=%x, ptr=%p\n", 
		c, s, d, 3735928559u, p);
	printf("og: char=%c, str=%s, int=%d, hex=%x, ptr=%p\n", 
		c, s, d, 3735928559u, p);

	return (0);
}
