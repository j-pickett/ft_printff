/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:46:00 by apickett          #+#    #+#             */
/*   Updated: 2019/06/21 17:46:06 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_flags(t_params *par, const char *s, int *i)
{
	while (FLAGS(s[*i]))
	{
		if (s[*i] == '#')
			par->hash = 1;
		else if (s[*i] == '0')
			par->zero = 1;
		else if (s[*i] == '-')
			par->min = 1;
		else if (s[*i] == '+')
			par->plus = 1;
		else if (s[*i] == ' ')
			par->space = 1;
		(*i)++;
	}
	if (!ISDIGIT(s[*i]) && s[*i] != '.' && !MODIFS(s[*i]) && !CONVRNS(s[*i]))
		exit(-1);
}

void		ft_width(t_params *par, const char *s, int *i)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->i0 = *i;
	while (ISDIGIT(s[*i]))
		(*i)++;
	if (!(head->tmp = ft_strsub(s, head->i0, (*i - head->i0))))
		exit(-1);
	par->width = ft_atoi(head->tmp);
	free(head->tmp);
	if (s[*i] != '.' && !MODIFS(s[*i]) && !CONVRNS(s[*i]))
		exit(-1);
	free(head);
}

void		ft_prec(t_params *par, const char *s, int *i)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	(*i)++;
	if (!ISDIGIT(s[*i]))
	{
		if (!MODIFS(s[*i]) && !CONVRNS(s[*i]))
			exit(-1);
		par->prec = 0;
		return ;
	}
	head->i0 = *i;
	while (ISDIGIT(s[*i]))
		(*i)++;
	if (!(head->tmp = ft_strsub(s, head->i0, (*i - head->i0))))
		exit(-1);
	par->prec = ft_atoi(head->tmp);
	free(head->tmp);
	if (!MODIFS(s[*i]) && !CONVRNS(s[*i]))
		exit(-1);
	free(head);
}

void		ft_modif(t_params *par, const char *s, int *i)
{
	if (s[*i] == 'h')
		par->modif = s[(*i) + 1] == 'h' ? 'H' : 'h';
	else if (s[*i] == 'l')
		par->modif = s[(*i) + 1] == 'l' ? 'L' : 'l';
	(*i)++;
	if (s[*i] == 'h' || s[*i] == 'l')
		(*i)++;
	if (!CONVRNS(s[*i]))
		exit(-1);
}

void		ft_get_params(const char *s, int *i, t_params *par)
{
	if (!ALLFLAGS(s[*i]))
		exit(-1);
	if (FLAGS(s[*i]))
		ft_flags(par, s, i);
	if (ISDIGIT(s[*i]))
		ft_width(par, s, i);
	if (s[*i] == '.')
		ft_prec(par, s, i);
	if (MODIFS(s[*i]))
		ft_modif(par, s, i);
	if (par->space && par->plus)
		par->space = 0;
}
