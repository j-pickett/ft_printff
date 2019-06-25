/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 21:08:34 by apickett          #+#    #+#             */
/*   Updated: 2018/04/30 21:08:44 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	if (!(s1[i] || s2[i]))
		return (1);
	while (s1[i] && s2[i])
	{
		if (ft_strncmp(s1, s2, n) != 0)
			return (0);
		i++;
	}
	return (1);
}
