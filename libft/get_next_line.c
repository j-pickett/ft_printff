/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:22:58 by apickett          #+#    #+#             */
/*   Updated: 2018/06/08 12:22:59 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_new_line(char **s, char **line, int fd, int bytes_read)
{
	t_newl *head;

	head = malloc(sizeof(t_newl));
	head->len = 0;
	while (s[fd][head->len] != '\n' && s[fd][head->len] != '\0')
		head->len++;
	if (s[fd][head->len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, head->len);
		head->tmp = ft_strdup(s[fd] + head->len + 1);
		free(s[fd]);
		s[fd] = head->tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][head->len] == '\0')
	{
		if (bytes_read == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	free(head);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[4096];
	int			bytes_read;
	char		buf[BUFF_SIZE + 1];
	t_newl		*head;

	head = malloc(sizeof(t_newl));
	if (fd <= -1 || line == NULL)
		return (-1);
	while ((bytes_read = read(fd, buf, BUFF_SIZE)) >= 1)
	{
		buf[bytes_read] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		head->temp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = head->temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (bytes_read <= -1)
		return (-1);
	else if (bytes_read == 0 && (s[fd] == NULL))
		return (0);
	free(head);
	return (ft_new_line(s, line, fd, bytes_read));
}
