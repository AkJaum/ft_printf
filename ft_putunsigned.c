#include "printf.h"

int ft_putunsigned(unsigned int n)
{
    unsigned long    nbr;
    int     count;
    char    c;
    
    count = 0;
    nbr = n;
    if (nbr >= 10)
    {
        ft_putunsigned(nbr / 10);
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