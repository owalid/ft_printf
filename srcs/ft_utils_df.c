#include "ft_printf.h"

char        *option_plus_df(t_output *output, size_t size, char *result, size_t *i)
{
    (void)size;
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
    char    *tmp2;

    if (output->str[0] == '-')
    {
        tmp = ft_strnew(output->size_flag->precision);
        while (*i < output->size_flag->precision - (ft_strlen(output->str) - 1))
            result[(*i)++] = '0';
        tmp2 = ft_strdup("-");
        result = ft_strjoin_free(tmp2, result);
        tmp = ft_itoa_base(ft_atoi(output->str) * -1, 10);
        result = ft_strjoin_free(result, tmp);
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
    char    *tmp2;
    (void)size;

    if (output->str[0] == '-')
    {
        tmp = ft_strnew(output->minsize);
        while (*i < output->minsize - (ft_strlen(output->str)))
            result[(*i)++] = '0';
        tmp2 = ft_strdup("-");
        result = ft_strjoin_free(tmp2, result);
        tmp = ft_itoa(ft_atoi(output->str) * -1);
        result = ft_strjoin_free(result, tmp);
    }
    else
    {
        while (*i < output->minsize - ft_strlen(output->str))
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
            result = ft_strjoin_free(tmp, result);
        }
    }
    return (result);
}