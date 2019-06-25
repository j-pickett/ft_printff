/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:08:20 by apickett          #+#    #+#             */
/*   Updated: 2019/06/21 17:47:46 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_init_fcts(t_fcts *fcts)
{
	fcts['c'] = &get_char;
	fcts['s'] = &get_str;
	fcts['p'] = &get_nbrs;
	fcts['d'] = &get_nbrs;
	fcts['i'] = &get_nbrs;
	fcts['o'] = &get_nbrs;
	fcts['u'] = &get_nbrs;
	fcts['x'] = &get_nbrs;
	fcts['X'] = &get_nbrs;
	fcts['f'] = &get_nbrs;
	fcts['%'] = &get_perc;
}

char		*ft_get_str(va_list ap, t_params par)
{
	t_helper	*head;
	t_fcts		tab[121];

	head = malloc(sizeof(t_helper));
	ft_init_fcts(tab);
	if (par.type == 'D' || par.type == 'O' || par.type == 'U')
		par.modif = 'l';
	if (par.type == 'D')
		par.type = 'd';
	if (par.type == 'O')
		par.type = 'o';
	if (par.type == 'U')
		par.type = 'u';
	head->tmp = (*tab[(int)par.type])(ap, par);
	free(head);
	return (head->tmp);
}

char		*ft_perc(char *str, int *i, const char *s, va_list ap)
{
	t_helper	*head;
	t_params	par;

	head = malloc(sizeof(t_helper));
	if (!(s[++(*i)]))
		exit(-1);
	ft_init_params(&par);
	while (s[*i])
	{
		if (!CONVRNS(s[*i]))
			ft_get_params(s, i, &par);
		else
		{
			par.type = s[*i];
			(*i)++;
			break ;
		}
	}
	if (!(head->tmp = ft_get_str(ap, par)))
		return (NULL);
	if (!(head->temp = ft_strjoin(str, head->tmp)))
		return (NULL);
	free(str);
	free(head);
	return (head->temp);
}

void		width_hlper(char *str, char *tmp, t_params par, int j)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->i = -1;
	if (par.prec != -1)
	{
		while (++head->i < par.width - ft_strlen(str))
			tmp[head->i] = ' ';
	}
	else
	{
		while (++head->i < par.width - ft_strlen(str))
			tmp[head->i] = par.zero ? '0' : ' ';
	}
	while (str[++j])
		tmp[head->i + j] = str[j];
	free(head);
}
