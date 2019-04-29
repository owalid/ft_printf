#include "libft.h"

int			ft_supdigit(int nb, int size)
{
    int		size_nb;

	size_nb = get_size_nb(nb);
    while (size && size_nb)
    {
        nb /= 10;
		size--;
        size_nb--;
    }
	return (nb);
}