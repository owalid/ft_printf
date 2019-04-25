
#include "libft.h"

char    *ft_str_from_char(char c)
{
    char    *result;

    if (!(result = ft_strnew(1)))
        return (NULL);
    result[0] = c;
    return (result);
}