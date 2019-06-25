/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:37:30 by apickett          #+#    #+#             */
/*   Updated: 2018/05/07 18:05:11 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		pos;

	pos = 0;
	i = 0;
	while (s1[pos])
		pos++;
	while (i < n && s2[i])
	{
		s1[pos] = s2[i];
		i++;
		pos++;
	}
	s1[pos] = '\0';
	return (s1);
}
