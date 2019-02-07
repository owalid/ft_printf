
#include "ft_printf.h"

void		add_char(char c, int opt)
{
	t_ptrbuff		*ptr;
	
	if (ft_strlen(ptr->str) == 0)
		ptr->size = 0;
	if (ptr->size == 1024 || opt)
	{
		write(1, str, size);
		ptr->str[0] = '\0';
		ptr->size = 0;
	}
	else
	{
		ptr->str[size] = c;
		ptr->size++;
	}
}
