/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:44:44 by apickett          #+#    #+#             */
/*   Updated: 2019/06/21 17:44:49 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*apply_char_flags(char c, t_params par)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->len = par.width;
	head->i = 0;
	if (!(head->str = ft_strnew(head->len)))
		exit(-1);
	if (par.min)
	{
		head->str[head->i] = c;
		while (++head->i < head->len)
			head->str[head->i] = ' ';
	}
	else
	{
		head->len--;
		head->str[head->len] = c;
		head->str[head->len] = c;
		head->str[head->len] = c;
		while (--head->len >= 0)
			head->str[head->len] = par.zero ? '0' : ' ';
	}
	free(head);
	return (head->str);
}

char	*get_char(va_list ap, t_params par)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	if (par.modif)
		if (par.modif != 'l')
			exit(-1);
	if (!(head->c = (char)va_arg(ap, int)))
	{
		head->c = 1;
		g_c_bool = 1;
	}
	if (par.width > 1)
		head->str = apply_char_flags(head->c, par);
	else
	{
		if (!(head->str = ft_strnew(1)))
			exit(-1);
		head->str[0] = head->c;
	}
	free(head);
	return (head->str);
}
