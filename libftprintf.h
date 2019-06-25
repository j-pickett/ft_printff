/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:09:42 by apickett          #+#    #+#             */
/*   Updated: 2019/06/21 16:09:44 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define FLAGS(x) (x == '#' || x == '0' || x == '-' || x == '+' || x == ' ')
# define MODIFS(x) (x == 'h' || x == 'l')
# define ALLFLAGS(x) (FLAGS(x) || MODIFS(x) || ISDIGIT(x) || x == '.')
# define CONV1(x) (x == 'd' || x == 'i' || x == 'o' || x == 'u')
# define CONV2(x) (x == 'x' || x == 'X'  || x == 'c' || x == 's' || x == 'p')
# define CONVRNS(x) (x == '%' || CONV1(x) || CONV2(x))

typedef struct	s_params
{
	char		hash;
	char		zero;
	char		min;
	char		plus;
	char		space;
	int			width;
	int			prec;
	char		modif;
	char		type;
}				t_params;

typedef	struct	s_nbrs
{
	uintmax_t	unmx;
	intmax_t	inmx;
	int			base;
	int			og_len;
	int			prec_len;
	char		*str;
	int			i;
}				t_nbrs;

typedef	struct	s_helper
{
	int			i;
	int			j;
	int			x;
	int			y;
	int			i0;
	int			dot;
	int			ret;
	int			len;
	int			c_bool;
	int			booly;
	char		*tmp;
	char		*temp;
	char		*str;
	char		*s2;
	intmax_t	ipart;
	intmax_t	dpart;
	uintmax_t	val2;
	long long	gnbr;
	double		nbr;
	char		*doot;
	char		c;
	char		*table;
	char		zero;
}				t_helper;

typedef char*	(*t_fcts)(va_list ap, t_params par);
int				g_c_bool;

void			width_hlper(char *str, char *tmp, t_params par, int j);
char			*int_prec(char *str, t_params par, char booly);
char			*int_width(char *str, t_params par);
char			*ft_left_ext(char *str, int extension);
char			*int_add_sign(char *str, t_params par);
uintmax_t		modif_uints(va_list ap, t_params par);
intmax_t		modif_ints(va_list ap, t_params par);
char			*ft_fix_pbs(char *str, t_params par, int booly);
char			*get_ints(va_list ap, t_params par);
char			*enuf_space(char *str, t_params par);
char			*ft_str_left_ext(char *str, int extension);
char			*ft_imaxtoa(intmax_t nb);
char			*shift_right(char *str, int dist);
void			ft_pf_putstr(char *str);
char			*apply_hash(char *str, t_params par, int og_len, int prec_len);
int				ft_printf(const char *format, ...);
char			*uitoa_base(uintmax_t nb, int base, t_params par);
void			ft_get_params(const char *s, int *i, t_params *par);
void			ft_init_params(t_params *par);
char			*get_nbrs(va_list ap, t_params par);
char			*get_char(va_list ap, t_params par);
char			*get_perc(va_list ap, t_params par);
char			*get_str(va_list ap, t_params par);
char			*ft_perc(char *str, int *i, const char *s, va_list ap);
void			ft_get_params(const char *s, int *i, t_params *par);
void			ft_init_params(t_params *par);
int				get_base(char c);

#endif
