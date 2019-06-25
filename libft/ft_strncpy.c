/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:02:34 by apickett          #+#    #+#             */
/*   Updated: 2018/04/30 22:01:03 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, unsigned int h)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)src;
	while (str[i] != '\0' && (i < h))
	{
		dest[i] = str[i];
		i++;
	}
	while (i < h)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
