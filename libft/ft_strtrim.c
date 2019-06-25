/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:29:54 by apickett          #+#    #+#             */
/*   Updated: 2018/04/30 15:10:15 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_istab(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

static	int		ft_len(const char *str)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	len--;
	while (ft_istab(str[len]))
		len--;
	if (len == 0)
		return (0);
	while (ft_istab(str[i]))
	{
		i++;
		len--;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*new;

	STRTRIM;
	if (s == NULL)
		return (NULL);
	z = ft_len(s);
	while (ft_istab(s[x]))
		x++;
	if (s[x] == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	new = (char *)malloc(sizeof(*new) * (z + 2));
	if (new == NULL)
		return (NULL);
	while (z + 1 > 0)
	{
		new[y] = s[x];
		z--;
		y++;
		x++;
	}
	new[y] = '\0';
	return (new);
}
