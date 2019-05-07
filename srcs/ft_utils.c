#include "ft_printf.h"

char        *ft_add_blank(t_output *output, char *result, int opt)
{
    char	*tmp;
    size_t     i;

    i = 0;
    tmp = ft_strnew(output->minsize - ft_strlen(result));
    while (i < output->minsize - ft_strlen(result))
        tmp[(i)++] = ' ';
    if (i != 0)
            result = (opt == 1) ? ft_strjoin(result, tmp) : ft_strjoin(tmp, result);
    ft_strdel(&tmp);
    return (result);
}