#include "ft_printf.h"

char        *option_point_p(t_output *output, char *result, size_t size)
{
    char    *tmp;
    char    *min;
    char    *tmp2;
    size_t  i;

    i = 0;
    if (output->str[0] == '-')
    {
        min = ft_strdup("-");
        tmp2 = ft_strdup("0x");
        tmp = ft_strnew(size);
        while (i < size - (ft_strlen(output->str) - 1))
            result[i++] = '0';
        result = ft_strjoin_free(min, result);
        tmp = ft_itoa(ft_atoi(output->str) * -1);
        result = ft_strjoin_free(tmp2, result);
        result = ft_strjoin_free(result, tmp);
    }
    else
    {
        while (i < size - (ft_strlen(output->str)))
            result[i++] = '0';
    }
    return (result);
}