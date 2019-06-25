/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:45:31 by apickett          #+#    #+#             */
/*   Updated: 2019/06/21 17:45:38 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_spacecount(intmax_t n)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->len = 1;
	if (n < 0)
	{
		n *= -1;
		head->len++;
	}
	while (n > 9)
	{
		n /= 10;
		head->len++;
	}
	free(head);
	return (head->len);
}

char	*ft_imaxtoa(intmax_t nb)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->i = ft_spacecount(nb) - 1;
	if (!(head->str = ft_strnew(ft_spacecount(nb))))
		return (NULL);
	if (nb <= 0)
	{
		if (nb == 0)
		{
			head->str[0] = '0';
			return (head->str);
		}
		head->str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		head->str[head->i] = nb % 10 + '0';
		nb /= 10;
		head->i--;
	}
	free(head);
	return (head->str);
}
