
int			ft_printf(const char *format, ...);
#include <limits.h>

int		main(int ac, char **av)
{
	unsigned char a = 10;
	ft_printf("heloooo %#4x %s %3.8f\n", a, "coucou", -15.35);
}