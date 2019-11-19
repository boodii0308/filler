/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:48:26 by tebatsai          #+#    #+#             */
/*   Updated: 2019/11/18 19:37:10 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

void		dry_double(t_all **all)
{
	int		i;

	i = 0;
	while (i < (*all)->pc[0])
	{
		free((*all)->lol[i]);
		i++;
	}
	(*all)->pc[0] = 0;
	(*all)->pc[1] = 0;
	free((*all)->lol);
}

void		get_piece(t_all **all, char *line, int j)
{
	int		i;

	i = 0;
	while (i < (*all)->pc[1] && *line)
	{
		if ((*line == '.' || *line == '*') && *line && i < (*all)->pc[1])
		{
			if (*line == '*')
			{
				(*all)->lol[j][i] = 1;
			}
			else
			{
				(*all)->lol[j][i] = -1;
			}
			i++;
		}
		line++;
	}
	return ;
}

void		put_lol(t_all **all)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	i = 0;
	while (j < (*all)->pc[0] && (i = get_next_line(0, &line)))
	{
		if (i == -1)
		{
			ft_putstr("ERROR ON LINE READ 2");
			return ;
		}
		get_piece(&(*all), line, j);
		j++;
		ft_strdel(&line);
	}
}

void		create_piece(t_all **all, char *line)
{
	int		i;

	i = 0;
	if ((*all)->lol)
		dry_double(&(*all));
	find_size((*all), line, &(*(*all)->pc));
	(*all)->lol = (int **)malloc(sizeof(int*) * (*all)->pc[0]);
	while (i < (*all)->pc[0])
	{
		(*all)->lol[i] = (int *)malloc(sizeof(int) * (*all)->pc[1]);
		i++;
	}
	put_lol(&(*all));
}
