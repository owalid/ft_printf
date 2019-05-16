/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_from_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 07:57:54 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 08:00:12 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_from_char(char c)
{
	char	*result;

	if (!(result = ft_strnew(1)))
		return (NULL);
	result[0] = c;
	return (result);
}
