/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:44:54 by apickett          #+#    #+#             */
/*   Updated: 2019/06/21 17:44:56 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*int_prec(char *str, t_params par, char booly)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	if (!(head->tmp = ft_strnew(booly ? par.prec + 1 : par.prec)))
		exit(-1);
	head->x = -1;
	head->y = -1;
	head->len = booly ? ft_strlen(str) - 1 : ft_strlen(str);
	while (++head->x < par.prec - head->len)
		head->tmp[head->x] = '0';
	while (str[++head->y])
		head->tmp[head->x + head->y] = str[head->y];
	free(str);
	return (head->tmp);
}

char		*int_width(char *str, t_params par)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->x = -1;
	if (!(head->tmp = ft_strnew(par.width)))
		exit(-1);
	if (par.min)
	{
		while (str[++head->x])
			head->tmp[head->x] = str[head->x];
		head->x--;
		while (++head->x < par.width)
			head->tmp[head->x] = ' ';
	}
	else
		width_hlper(str, head->tmp, par, -1);
	free(str);
	return (head->tmp);
}

char		*ft_left_ext(char *str, int extension)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->len = ft_strlen(str) + extension;
	head->i = 0;
	if (!(head->tmp = ft_strnew(head->len)))
		return (NULL);
	ft_bzero(head->tmp, head->len);
	while (extension + head->i < head->len)
	{
		head->tmp[extension + head->i] = str[head->i];
		head->i++;
	}
	free(head);
	return (head->tmp);
}

char		*int_add_sign(char *str, t_params par)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	if (par.width <= par.prec)
	{
		if (!(head->tmp = ft_left_ext(str, 1)))
			exit(-1);
		free(str);
		head->tmp[0] = par.space ? ' ' : '+';
		free(head);
		return (head->tmp);
	}
	else
	{
		if (par.min)
		{
			str = shift_right(str, 1);
			str[0] = par.space ? ' ' : '+';
		}
		else
			str[0] = par.space ? ' ' : '+';
		free(head);
		return (str);
	}
}

char		*get_nbrs(va_list ap, t_params par)
{
	t_nbrs *nbrs;

	nbrs = malloc(sizeof(t_nbrs));
	if (par.prec != -1 || par.min || par.type == 'p')
		par.zero = 0;
	if (par.type == 'd' || par.type == 'i' || par.type == 'D')
		return (get_ints(ap, par));
	nbrs->inmx = modif_uints(ap, par);
	nbrs->base = get_base(par.type);
	nbrs->str = uitoa_base(nbrs->inmx, nbrs->base, par);
	nbrs->og_len = ft_strlen(nbrs->str);
	if (par.prec > nbrs->og_len)
		nbrs->str = int_prec(nbrs->str, par, 0);
	nbrs->prec_len = ft_strlen(nbrs->str);
	if (par.width > nbrs->prec_len)
		nbrs->str = int_width(nbrs->str, par);
	if (par.hash && (((par.type == 'x' || par.type == 'X') && nbrs->inmx) ||
	(par.type == 'o' && par.prec <= nbrs->og_len)))
		nbrs->str = apply_hash(nbrs->str, par, nbrs->og_len, nbrs->prec_len);
	free(nbrs);
	return (nbrs->str);
}
