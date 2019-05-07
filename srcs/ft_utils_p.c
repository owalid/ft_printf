#include "ft_printf.h"

char        *option_point_p(t_output *output, char *result)
{
    char    *tmp;
    size_t  i;

    i = 0;
    if (output->str[0] == '-')
    {
        tmp = ft_strnew(output->size_flag->precision);
        while (i < output->size_flag->precision - (ft_strlen(output->str) - 1))
            result[i++] = '0';
        result = ft_strjoin("-", result);
        tmp = ft_itoa(ft_atoi(output->str) * -1);
        result = ft_strjoin("0x", result);
        result = ft_strjoin(result, tmp);
        ft_strdel(&tmp);
    }
    else
    {
        while (i < output->size_flag->precision - ft_strlen(output->str))
            result[i++] = '0';
    }
    return (result);
}