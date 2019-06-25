/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:49:32 by apickett          #+#    #+#             */
/*   Updated: 2019/06/21 17:49:34 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_no_perc(char *str, int *i, const char *s)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->i0 = *i;
	while (s[*i] && s[*i] != '%')
		(*i)++;
	if (!(head->tmp = ft_strsub(s, head->i0, (*i - head->i0))))
		exit(-1);
	if (!(head->temp = ft_strjoin(str, head->tmp)))
		exit(-1);
	free(str);
	free(head->tmp);
	free(head);
	return (head->temp);
}

int		ft_do_something(const char *s, va_list ap)
{
	t_helper *head;

	head = malloc(sizeof(t_helper));
	head->len = 0;
	head->i = 0;
	if (!(head->str = ft_strnew(0)))
		return (-1);
	while (s[head->i])
	{
		if (s[head->i] != '%')
		{
			if (!(head->str = ft_no_perc(head->str, &head->i, s)))
				return (-1);
		}
		else
		{
			if (!(head->str = ft_perc(head->str, &head->i, s, ap)))
				return (-1);
		}
	}
	ft_pf_putstr(head->str);
	head->len = ft_strlen(head->str);
	free(head->str);
	free(head);
	return (head->len);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_helper	*head;

	head = malloc(sizeof(t_helper));
	g_c_bool = 0;
	if (!(format))
		return (-1);
	if (!(*format))
		return (0);
	va_start(ap, format);
	head->ret = ft_do_something(format, ap);
	va_end(ap);
	free(head);
	return (head->ret);
}
