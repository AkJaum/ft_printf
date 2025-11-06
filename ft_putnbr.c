#include "printf.h"

int ft_putnbr(int n)
{
    long    nbr;
    int     count;
    char    c;
    
    count = 0;
    nbr = n;
    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        nbr = -nbr;
    }
    if (nbr >= 10)
    {
        ft_putnbr(nbr / 10);
        c = (nbr % 10) + '0';
        write(1, &c, 1);
        count++;
    }
    if (nbr < 10)
    {
        c = nbr + '0';
        write(1, &c, 1);
        count++;
    }
    return (count);
}