/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:45:47 by apickett          #+#    #+#             */
/*   Updated: 2019/06/21 17:45:50 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#define UNMAX nbrs->unmx > 4294967295 && !par.modif
#define IMAX if (!(head->str = ft_imaxtoa(nbrs->inmx)))exit(-1);

intmax_t	modif_ints(va_list ap, t_params par)
{
	t_nbrs *nbrs;

	nbrs = malloc(sizeof(t_nbrs));
	if (par.modif == 'l')
		nbrs->inmx = va_arg(ap, long);
	else if (par.modif == 'L')
		nbrs->inmx = va_arg(ap, long long);
	else
		nbrs->inmx = va_arg(ap, int);
	if (par.modif == 'h')
		nbrs->inmx = (short)nbrs->inmx;
	else if (par.modif == 'H')
		nbrs->inmx = (char)nbrs->inmx;
	free(nbrs);
	return (nbrs->inmx);
}

uintmax_t	modif_uints(va_list ap, t_params par)
{
	t_nbrs	*nbrs;

	nbrs = malloc(sizeof(t_nbrs));
	if (par.modif == 'l')
		nbrs->unmx = va_arg(ap, unsigned long);
	else if (par.modif == 'L' || par.type == 'O' || par.type == 'U')
		nbrs->unmx = va_arg(ap, unsigned long long);
	else
		nbrs->unmx = va_arg(ap, unsigned long long);
	if (par.modif == 'h')
		nbrs->unmx = (unsigned short)nbrs->unmx;
	else if (par.modif == 'H')
		nbrs->unmx = (unsigned char)nbrs->unmx;
	if ((par.type == 'x' || par.type == 'X') && UNMAX)
		return (0);
	if (nbrs->unmx >= 4294967296 && par.type == 'u')
	{
		if (par.modif)
			return (nbrs->unmx);
		nbrs->i = nbrs->unmx - 4294967296;
		nbrs->unmx = 0 + nbrs->i;
	}
	free(nbrs);
	return (nbrs->unmx);
}

void		fix_pb_hlper(char *str, int i)
{
	if (str[0] == '+' && str[1] == ' ')
	{
		i++;
		while (str[i] == ' ')
			i++;
		str[i - 1] = '+';
		str[0] = ' ';
	}
}

char		*ft_fix_pbs(char *str, t_params par, int booly)
{
	t_helper	*head;

	head = malloc(sizeof(t_helper));
	head->y = 0;
	head->x = 0;
	if (booly && (par.zero || par.prec != -1))
	{
		while (str[head->x] != '-')
			head->x++;
		if (head->x != 0)
		{
			str[head->x] = '0';
			while (str[head->y] != '0')
				head->y++;
			str[head->y] = '-';
		}
	}
	else if (par.plus && !par.zero)
		fix_pb_hlper(str, head->x);
	free(head);
	return (str);
}

char		*get_ints(va_list ap, t_params par)
{
	t_nbrs		*nbrs;
	t_helper	*head;

	nbrs = malloc(sizeof(t_nbrs));
	head = malloc(sizeof(t_helper));
	head->booly = 0;
	if ((nbrs->inmx = modif_ints(ap, par)) < 0)
		head->booly = 1;
	if (!nbrs->inmx && !par.prec)
		head->str = ft_strnew(0);
	else
		IMAX;
	head->len = ft_strlen(head->str);
	if (par.prec > (head->booly ? head->len - 1 : head->len))
		head->str = int_prec(head->str, par, head->booly);
	if (par.width > ft_strlen(head->str))
		head->str = int_width(head->str, par);
	if ((par.space && nbrs->inmx > 0) || (par.plus && nbrs->inmx >= 0))
		head->str = int_add_sign(head->str, par);
	head->str = ft_fix_pbs(head->str, par, head->booly);
	free(head);
	free(nbrs);
	return (head->str);
}
