/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:13:16 by apickett          #+#    #+#             */
/*   Updated: 2018/04/19 20:27:29 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	total_len;

	i = 0;
	j = 0;
	total_len = 0;
	while (dst[i] != '\0')
		++i;
	while (src[total_len] != '\0')
		++total_len;
	if (dstsize <= i)
		total_len = total_len + dstsize;
	else
		total_len = total_len + i;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (total_len);
}
