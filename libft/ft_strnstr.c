/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:54:40 by apickett          #+#    #+#             */
/*   Updated: 2018/04/19 20:05:53 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		x;
	size_t		y;

	x = 0;
	while (x < len && s1[x] != '\0')
	{
		y = 0;
		while (x + y < len && s1[x + y] == s2[y] && s2[y] != '\0')
			y++;
		if (s2[y] == '\0')
			return ((char *)s1 + x);
		x++;
	}
	return (NULL);
}
