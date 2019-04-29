
#include "ft_printf.h"
#include <limits.h>

int		main(int ac, char **av)
{
	unsigned char a = 10;
	ft_printf("heloooo %#4x %s %3.6f\n", a, "coucou", 1555888.54891);
}