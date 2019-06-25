/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:54:50 by apickett          #+#    #+#             */
/*   Updated: 2018/04/19 20:22:32 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *sub_str)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	while (sub_str[0] == '\0' && str[0] == '\0')
		return ((char *)str);
	while (str[x] != '\0')
	{
		y = 0;
		while (str[x + y] == sub_str[y] && sub_str[y] != '\0')
			y++;
		if (sub_str[y] == '\0')
			return ((char *)str + x);
		x++;
	}
	return (NULL);
}
