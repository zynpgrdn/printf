#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int a = 0;
    int b = 0;
   int x = 42;
a = ft_printf("%p\n", &x);
b = printf("%p\n", &x);
printf("bizim: %d, orijinal: %d\n\n", a, b);
    return (0);
}