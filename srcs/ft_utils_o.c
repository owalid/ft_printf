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
        (*i)++;
    if  (output->option->zero && !output->option->min && (ft_strlen(output->str) < size
                    || output->minsize > ft_strlen(output->str)) && !output->is_null)
        result = option_zero_df(output, size, result, &(*i));
    result = ft_strjoin(result, output->str);
    return (result);
}