/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fnhelp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:43:51 by apickett          #+#    #+#             */
/*   Updated: 2019/06/21 17:51:17 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*ft_str_left_ext(char *str, int extension)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->len = ft_strlen(str) + extension;
	head->i = 0;
	if (!(head->tmp = ft_strnew(head->len)))
		return (NULL);
	ft_bzero(head->tmp, head->len);
	while ((extension + head->i) < head->len)
	{
		head->tmp[extension + head->i] = str[head->i];
		head->i++;
	}
	free(head);
	return (head->tmp);
}

char		*enuf_space(char *str, t_params par)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->i = 0;
	if (par.min)
	{
		str = shift_right(str, 2);
		str[0] = '0';
		str[1] = par.type == 'X' ? 'X' : 'x';
		return (str);
	}
	else
	{
		if (par.zero)
		{
			str[1] = par.type == 'X' ? 'X' : 'x';
			return (str);
		}
		while (str[head->i] == ' ')
			head->i++;
		str[head->i - 2] = '0';
		str[head->i - 1] = par.type == 'X' ? 'X' : 'x';
		free(head);
		return (str);
	}
}

void		ft_pf_putstr(char *str)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->zero = '\0';
	head->i = -1;
	while (str[++head->i])
	{
		if (str[head->i] == 1)
		{
			if (g_c_bool)
				write(1, &head->zero, 1);
			else
				write(1, &str[head->i], 1);
		}
		else
			write(1, &str[head->i], 1);
	}
	free(head);
}

int			get_base(char c)
{
	if (c == 'o' || c == 'O')
		return (8);
	if (c == 'u' || c == 'U')
		return (10);
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	return (0);
}

void		ft_init_params(t_params *par)
{
	par->hash = 0;
	par->zero = 0;
	par->min = 0;
	par->plus = 0;
	par->space = 0;
	par->width = -1;
	par->prec = -1;
	par->modif = 0;
	par->type = 0;
}
