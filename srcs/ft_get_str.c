/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:45:03 by apickett          #+#    #+#             */
/*   Updated: 2019/06/21 17:45:05 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_helper_str(int i, char *str, char *tmp, t_params par)
{
	while (str[++i])
		tmp[i] = str[i];
	while (i < par.width)
	{
		tmp[i] = ' ';
		i++;
	}
}

char	*apply_str_flags(char *str, t_params par, int i, int j)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	if (!(head->tmp = ft_strnew(par.width)))
		exit(-1);
	if (par.min)
		ft_helper_str(i, str, head->tmp, par);
	else
	{
		head->len = ft_strlen(str);
		while (++i < par.width - head->len)
			head->tmp[i] = par.zero ? '0' : ' ';
		while ((i + j) < par.width)
		{
			head->tmp[i + j] = str[j];
			j++;
		}
	}
	free(head);
	return (head->tmp);
}

char	*null_str(void)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	if (!(head->str = ft_strnew(6)))
		exit(-1);
	head->str = "(null)\0";
	free(head);
	return (head->str);
}

char	*get_str(va_list ap, t_params par)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	if (par.modif)
		if (par.modif != 'l')
			exit(-1);
	if (!(head->str = va_arg(ap, char*)))
		head->str = null_str();
	if (par.prec != -1 && par.prec < ft_strlen(head->str))
	{
		if (!(head->str = ft_strndup(head->str, par.prec)))
			exit(-1);
	}
	if (ft_strlen(head->str) < par.width)
		head->str = apply_str_flags(head->str, par, -1, 0);
	free(head);
	return (head->str);
}
