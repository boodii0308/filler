/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:38:57 by tebatsai          #+#    #+#             */
/*   Updated: 2019/06/04 21:55:44 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_newline(char **s)
{
	size_t		i;
	char		*t;

	t = *s;
	i = 0;
	while (t[i] != '\n')
	{
		if (!(t[i++]))
		{
			return (0);
		}
	}
	return (1);
}

static int		get_add(int fd, char **line, char *buff, char **s)
{
	int			ret;
	char		*t;

	if (!(s[fd % 4096]))
		if (!(s[fd % 4096] = ft_strnew(0)))
			return (0);
	while (!(check_newline(&s[fd % 4096])) && (ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		t = s[fd % 4096];
		s[fd % 4096] = ft_strjoin(t, buff);
		ft_strdel(&t);
	}
	*line = ft_strsub(s[fd % 4096], 0, ft_strclen(s[fd % 4096], '\n'));
	ft_strdel(&buff);
	if (*s[fd % 4096])
	{
		if (check_newline(&s[fd % 4096]))
			ft_strcpy(s[fd % 4096], ft_strchr(s[fd % 4096], '\n') + 1);
		else
			ft_strdel(&s[fd % 4096]);
		return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*s[4096];
	char		*buff;

	if (!(buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (fd == -1 || !line || BUFF_SIZE < 1 || read(fd, buff, 0))
		return (-1);
	if (get_add(fd, line, buff, s))
		return (1);
	return (0);
}
