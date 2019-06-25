/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:38:38 by apickett          #+#    #+#             */
/*   Updated: 2018/04/23 16:10:48 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t len)
{
	char			*s1;
	char			*s2;
	unsigned int	i;

	i = 0;
	s1 = (char *)dest;
	s2 = (char *)src;
	if (s2 < s1)
	{
		while (len--)
			s1[len] = s2[len];
	}
	else
		ft_memcpy(s1, s2, len);
	return (dest);
}
