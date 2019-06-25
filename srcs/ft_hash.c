/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:45:15 by apickett          #+#    #+#             */
/*   Updated: 2019/06/21 17:45:23 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#define CHUNGUS if (!(head->tmp = ft_str_left_ext(str, 2))) exit(-1);

char		*shift_right(char *str, int dist)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->i = 0;
	while (str[head->i] != ' ')
		head->i++;
	while (--head->i >= 0)
		str[head->i + dist] = str[head->i];
	while (++head->i < dist)
		str[head->i] = ' ';
	return (str);
}

char		*hash_helper(char *str, t_params par)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->i = 0;
	if (par.zero)
		return (str);
	if (par.min)
	{
		str = shift_right(str, 1);
		str[0] = '0';
		free(head);
		return (str);
	}
	else
	{
		while (str[head->i] == ' ')
			head->i++;
		str[head->i - 1] = '0';
		free(head);
		return (str);
	}
}

char		*octal_hash(char *str, t_params par, int og_len)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	if (str[0] == '0')
		return (str);
	if (par.width > og_len)
		return (hash_helper(str, par));
	else
	{
		if (!(head->tmp = ft_str_left_ext(str, 1)))
			exit(-1);
		free(str);
		head->tmp[0] = '0';
		free(head);
		return (head->tmp);
	}
}

void		hash_min(char *str, char *tmp, t_params par, int prec_len)
{
	if (par.width - prec_len == 1)
	{
		if (!(tmp = ft_str_left_ext(str, 1)))
			exit(-1);
		free(str);
		tmp[0] = par.type == 'X' ? 'X' : 'x';
		tmp = shift_right(tmp, 1);
		tmp[0] = '0';
	}
	else
	{
		if (!(tmp = ft_str_left_ext(str, 2)))
			exit(-1);
		free(str);
		tmp[0] = '0';
		tmp[1] = par.type == 'X' ? 'X' : 'x';
	}
}

char		*apply_hash(char *str, t_params par, int og_len, int prec_len)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->tmp = NULL;
	if (par.type == 'o')
		return (octal_hash(str, par, og_len));
	if (par.width - prec_len > 1)
		return (enuf_space(str, par));
	if (par.min)
		hash_min(str, head->tmp, par, prec_len);
	else
	{
		if (par.width - prec_len == 1)
		{
			if (!(head->tmp = ft_str_left_ext(str, 1)))
				exit(-1);
		}
		else
			CHUNGUS;
		free(str);
		head->tmp[0] = '0';
		head->tmp[1] = par.type == 'X' ? 'X' : 'x';
	}
	free(head);
	return (head->tmp);
}
