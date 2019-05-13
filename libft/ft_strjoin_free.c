#include "libft.h"

char		*ft_strjoin_free(char const *s1, char const *s2)
{
	char		*result;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!s1 || !s2 || !(result = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	while (s1[j])
	{
		result[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
    ft_strdel((char**)&s2);
	ft_strdel((char**)&s1);
	return (result);
}
