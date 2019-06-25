/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:32:56 by apickett          #+#    #+#             */
/*   Updated: 2018/04/24 19:33:44 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	if (!(s1[i] || s2[i]))
		return (1);
	while (s1[i] && s2[i])
	{
		if (ft_strcmp(s1, s2) != 0)
			return (0);
		i++;
	}
	return (1);
}
