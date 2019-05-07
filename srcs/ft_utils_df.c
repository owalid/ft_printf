#include "ft_printf.h"

char        *option_plus(t_output *output, size_t size, char *result, int *i)
{
    if (ft_strlen(output->str) < size && !output->option->min)
    {
        while (*i < size - ft_strlen(output->str))
            result[*i++] = ' ';
    }
    if (output->str[0] != '-')
    {
        result[*i++] = '+';
        output->size_flag->precision += output->option->point;
    }
    return (result);
}


char        *option_point(t_output *output, size_t size, char *result, int *i)
{
    char    *tmp;

    if (output->str[0] == '-')
    {
        tmp = ft_strnew(output->size_flag->precision);
        while (*i < output->size_flag->precision - (ft_strlen(output->str) - 1))
            result[*i++] = '0';
        result = ft_strjoin("-", result);
        tmp = ft_itoa(ft_atoi(output->str) * -1);
        result = ft_strjoin(result, tmp);
        ft_strdel(&tmp);
        return(result);
    }
    else
    {
        while (*i < output->size_flag->precision - ft_strlen(output->str))
            result[*i++] = '0';
    }
    return (result);
}

char        *option_zero(t_output *output, size_t size, char *result, int *i)
{
    char    *tmp;

    if (output->str[0] == '-')
    {
        tmp = ft_strnew(output->minsize);
        while (*i < output->minsize - (ft_strlen(output->str)))
            result[*i++] = '0';
        result = ft_strjoin("-", result);
        tmp = ft_itoa(ft_atoi(output->str) * -1);
        result = ft_strjoin(result, tmp);
        ft_strdel(&tmp);
        return(result);
    }
    else
    {
        while (*i < size - ft_strlen(output->str))
            result[*i++] = '0';
    }
    return (result);
}

char        *option_hash(t_output *output, size_t size, char *result, int *i)
{
    if (output->conv_type == 'x' || output->conv_type == 'X')
    {
        result[*i] = '0';
        result[*i + 1] = 'x';
    }
    if (output->conv_type == 'o')
        result[*i] = '0';
    result = ft_strjoin(result, output->str);
    *i++;
    if (ft_strlen(output->str) < size)
    {
        while (*i < size - ft_strlen(output->str))
        {
            result[*i] = ' ';
            *i += 1;
        }
    }
    return (result);
}