/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:44:37 by apickett          #+#    #+#             */
/*   Updated: 2018/04/26 15:48:31 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		cnt(char const *s, char c)
{
	unsigned int i;
	unsigned int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char		*ft_splitdup(const char *s1, size_t n)
{
	char	*cpy;

	cpy = (char *)malloc(sizeof(char) * n + 1);
	if (cpy == NULL)
		return (NULL);
	cpy = ft_strncpy(cpy, s1, n);
	cpy[n] = '\0';
	return (cpy);
}

char			**ft_strsplit(char const *s, char c)
{
	STRSPLIT_VARS;
	if (!s || (!(table = (char **)malloc(sizeof(char *) * (cnt(s, c)) + 1))))
		return (NULL);
	while (s[x])
	{
		while (s[x] == c)
			x++;
		y = x;
		while (s[x] && s[x] != c)
			x++;
		if (x > y)
		{
			table[z] = ft_splitdup(s + y, x - y);
			z++;
		}
	}
	table[z] = NULL;
	return (table);
}
