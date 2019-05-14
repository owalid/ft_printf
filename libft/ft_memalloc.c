/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:07:54 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/14 11:35:51 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*result;

	if (size == 0)
		size = 1;
	if ((result = malloc(size)) == NULL)
		return (NULL);
	result = ft_memset(result, 0, size);
	return (result);
}
