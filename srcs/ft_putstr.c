#include "ft_printf.h"

int    ft_putstr(char *str)
{
    if (!str)
    {
        write(1, "(null)", 6);
        return (0);
    }
    write(1, str, ft_strlen(str));
    return (ft_strlen(str));
}