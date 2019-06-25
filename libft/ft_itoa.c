/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:22:20 by apickett          #+#    #+#             */
/*   Updated: 2018/04/30 15:11:06 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	bfr;

	len = ft_len(n);
	bfr = n;
	if (n < 0)
	{
		bfr = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = bfr % 10 + '0';
	while (bfr /= 10)
		str[--len] = bfr % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
