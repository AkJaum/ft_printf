#include "ft_printf.h"

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
