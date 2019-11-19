/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:52:09 by tebatsai          #+#    #+#             */
/*   Updated: 2019/11/18 19:59:46 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

void		get_input(t_all **all, char *line, int j)
{
	int		i;

	i = 0;
	while (i < (*all)->big[1] && *line)
	{
		if ((*line == '.' || *line == 'O' || *line == 'X'
		|| *line == 'o' || *line == 'x') && *line && i < (*all)->big[1])
		{
			if (*line == 'O' || *line == 'o')
			{
				(*all)->pla[j][i] = (*all)->p == 'o' ? 0 : 1;
			}
			else if (*line == 'X' || *line == 'x')
			{
				(*all)->pla[j][i] = (*all)->p == 'o' ? 1 : 0;
			}
			else
			{
				(*all)->pla[j][i] = 50;
			}
			i++;
		}
		line++;
	}
	return ;
}

void		clean_up(t_all **all)
{
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	(*all)->posi = 1;
	(*all)->pos[0] = 0;
	(*all)->pos[1] = 0;
	(*all)->pos[2] = 50;
	(*all)->pos[3] = 50;
	(*all)->max = 0;
	while (i[0] < (*all)->big[0])
	{
		i[1] = 0;
		while (i[1] < (*all)->big[1])
		{
			(*all)->pla[i[0]][i[1]] = 0;
			i[1]++;
		}
		i[0]++;
	}
}

void		get_map(t_all **all)
{
	int		j;
	int		l;
	char	*line;

	l = 0;
	j = 0;
	clean_up(&(*all));
	while (j < (*all)->big[0] && (l = get_next_line(0, &line)))
	{
		if (l == -1)
		{
			ft_putstr("ERROR ON LINE READ 2");
			return ;
		}
		if (line[0] == '0' || line[0] == '1')
		{
			get_input(&(*all), line, j);
			j++;
		}
		ft_strdel(&line);
	}
	turn_to_rad(&(*all));
	return ;
}
