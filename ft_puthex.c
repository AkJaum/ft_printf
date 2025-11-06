#include "printf.h"

int ft_puthex(unsigned int n, char format)
{
    char    *hexl;
    char    *hexu;
    int     count;
    
    count = 0;
    hexl = "0123456789abcdef";
    hexu = "0123456789ABCDEF";
    if (format == 'x')
    {
        while (n >= 16)
        {
            ft_putchar(hexl[n % 16]);
            n /= 16;
            count++;
        }
        ft_putchar(hexl[n]);
        count++;
    }
    else if (format == 'X')
    {
        while (n >= 16)
        {
            ft_putchar(hexu[n % 16]);
            n /= 16;
            count++;
        }
        ft_putchar(hexu[n]);
        count++;
    }
    return (count);
}