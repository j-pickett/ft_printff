/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:15:26 by apickett          #+#    #+#             */
/*   Updated: 2018/06/13 22:26:04 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_newl
{
	int		len;
	char	*tmp;
	char	*temp;
}				t_newl;

int				get_next_line(const int fd, char **line);
int				ft_new_line(char **str, char **line, int fd, int ret);

#endif
