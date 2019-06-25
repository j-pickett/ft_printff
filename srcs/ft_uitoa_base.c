/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:49:46 by apickett          #+#    #+#             */
/*   Updated: 2019/06/21 17:49:49 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#define PRECSTR if (!par.prec)return (ft_strnew(0));
#define NEWSTR if (!(head->str = ft_strnew(1)))exit(-1);

int		ft_spacecount_ub(uintmax_t n, int base)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->len = 1;
	while (n >= (uintmax_t)base)
	{
		n /= base;
		head->len++;
	}
	free(head);
	return (head->len);
}

char	*ptr_add_x(char *str)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	if (!(head->tmp = ft_str_left_ext(str, 2)))
		exit(-1);
	free(str);
	head->tmp[0] = '0';
	head->tmp[1] = 'x';
	free(head);
	return (head->tmp);
}

char	*uitoa_base(uintmax_t nb, int base, t_params par)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->table = (par.type == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	head->len = ft_spacecount_ub(nb, base);
	if (nb == 0 && par.type != 'p')
	{
		PRECSTR;
		NEWSTR;
		head->str[0] = '0';
		return (head->str);
	}
	if (!(head->str = ft_strnew(head->len)))
		exit(-1);
	while (head->len > 0)
	{
		head->str[head->len - 1] = head->table[nb % base];
		head->len--;
		nb /= base;
	}
	if (par.type == 'p')
		head->str = ptr_add_x(head->str);
	free(head);
	return (head->str);
}
