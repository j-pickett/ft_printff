/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 12:49:30 by apickett          #+#    #+#             */
/*   Updated: 2018/04/23 13:50:16 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*db;
	char			*sb;

	i = 0;
	db = (char *)dest;
	sb = (char *)src;
	while (i < n)
	{
		db[i] = sb[i];
		i++;
	}
	return (dest);
}
