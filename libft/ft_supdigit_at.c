#include "libft.h"

int			ft_supdigit_at(int nb, int rank)
{
	nb -= ft_pow(get_digit_at(nb, rank), rank);
	return (nb);
}
