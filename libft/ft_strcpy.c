/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:40:57 by apickett          #+#    #+#             */
/*   Updated: 2018/04/19 20:11:55 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	if (src[i] == '\0')
	{
		dest[i] = '\0';
		return (dest);
	}
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
		dest[i] = '\0';
	}
	return (dest);
}
