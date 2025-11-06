#include "printf.h"

int main(void)
{
    int n;
    int *ptr;
    
    n = 42;
    ptr = &n;
    ft_printf("teste str %s teste char %c teste num %d teste unsigned num %u teste hexl %x teste hexu %X teste porcentagem %%!\n", "Betola", 'A', 42, 500, 255, 255);
    printf("Ponteiro: %p\n", &ptr);
}