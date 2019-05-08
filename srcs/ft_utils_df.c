#include "ft_printf.h"

char        *option_plus_df(t_output *output, size_t size, char *result, size_t *i)
{
    // if (output->str[0] == '-')
    //     size++;
    if (ft_strlen(output->str) < size && !output->option->min)
    {
        while (*i < size - ft_strlen(output->str))
            result[(*i)++] = ' ';
    }
    if (output->str[0] != '-')
    {
        result[(*i)++] = '+';
        output->size_flag->precision += output->option->point;
    }
    return (result);
}


char        *option_point_df(t_output *output, char *result, size_t *i)
{
    char    *tmp;

    if (output->str[0] == '-')
    {
        tmp = ft_strnew(output->size_flag->precision);
        while (*i < output->size_flag->precision - (ft_strlen(output->str) - 1))
            result[(*i)++] = '0';
        result = ft_strjoin("-", result);
        tmp = ft_itoa(ft_atoi(output->str) * -1);
        result = ft_strjoin(result, tmp);
        ft_strdel(&tmp);
    }
    else
    {
        while (*i < output->size_flag->precision - ft_strlen(output->str))
            result[(*i)++] = '0';
    }
    return (result);
}

char        *option_zero_df(t_output *output, size_t size, char *result, size_t *i)
{
    char    *tmp;

    if (output->str[0] == '-')
    {
        tmp = ft_strnew(output->minsize);
        while (*i < output->minsize - (ft_strlen(output->str)))
            result[(*i)++] = '0';
        result = ft_strjoin("-", result);
        tmp = ft_itoa(ft_atoi(output->str) * -1);
        result = ft_strjoin(result, tmp);
        ft_strdel(&tmp);
    }
    else
    {
        while (*i < size - ft_strlen(output->str))
            result[(*i)++] = '0';
    }
    return (result);
}

char        *option_space_df(t_output *output, char *result)
{
    char        *tmp;

    if (result[0] != '-' || output->minsize > ft_strlen(result))
    {
        if (output->minsize > ft_strlen(result))
            result = ft_add_blank(output, result, 0);
        else
        {
            tmp = ft_str_from_char(' ');
            result = ft_strjoin(tmp, result);
            ft_strdel(&tmp);
        }
    }
    return (result);
}