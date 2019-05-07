#include "ft_printf.h"

char        *option_hash_o(t_output *output, size_t size, char *result, size_t *i)
{
    if (output->conv_type == 'x' || output->conv_type == 'X')
    {
        result[*i] = '0';
        result[++(*i)] = 'x';
    }
    if (output->conv_type == 'o')
        result[*i] = '0';
    result = ft_strjoin(result, output->str);
    (*i)++;
    if (ft_strlen(output->str) < size)
    {
        while (*i < size - ft_strlen(output->str))
            result[++(*i)] = ' ';
    }
    return (result);
}