
#include "ft_printf.h"
#include <limits.h>

int		main(int ac, char **av)
{
	unsigned char a = 10;
	ft_printf("heloooo %#4x %s", a, "coucou");
}
