/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perc_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:52:59 by apickett          #+#    #+#             */
/*   Updated: 2019/06/21 17:53:04 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*perc_flags(char *str, t_params par)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->i = -1;
	if (!(head->tmp = ft_strnew(par.width)))
		exit(-1);
	if (par.min)
	{
		head->tmp[++head->i] = '%';
		while (++head->i < par.width)
			head->tmp[head->i] = ' ';
	}
	else
	{
		while (++head->i < par.width - 1)
			head->tmp[head->i] = par.zero ? '0' : ' ';
		head->tmp[head->i] = '%';
	}
	free(str);
	free(head);
	return (head->tmp);
}

char	*get_perc(va_list ap, t_params par)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	(void)ap;
	if (!(head->str = ft_strnew(1)))
		exit(-1);
	head->str[0] = '%';
	if (par.width > 1)
		head->str = perc_flags(head->str, par);
	free(head);
	return (head->str);
}
