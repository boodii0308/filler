/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:00:56 by tebatsai          #+#    #+#             */
/*   Updated: 2019/11/18 20:01:06 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

void		lets_heat(t_all **all, int w[2])
{
	if (w[0] > 0 && w[1] > 0 && w[1] < (*all)->big[1] - 1)
	{
		if ((*all)->pla[w[0] - 1][w[1] - 1] == 50)
			(*all)->pla[w[0] - 1][w[1] - 1] = (*all)->posi + 1;
		if ((*all)->pla[w[0] - 1][w[1]] == 50)
			(*all)->pla[w[0] - 1][w[1]] = (*all)->posi + 1;
		if ((*all)->pla[w[0] - 1][w[1] + 1] == 50)
			(*all)->pla[w[0] - 1][w[1] + 1] = (*all)->posi + 1;
	}
	if (w[0] < (*all)->big[0] - 1 && w[1] > 0 && w[1] < (*all)->big[1] - 1)
	{
		if ((*all)->pla[w[0] + 1][w[1] + 1] == 50)
			(*all)->pla[w[0] + 1][w[1] + 1] = (*all)->posi + 1;
		if ((*all)->pla[w[0] + 1][w[1]] == 50)
			(*all)->pla[w[0] + 1][w[1]] = (*all)->posi + 1;
		if ((*all)->pla[w[0] + 1][w[1] - 1] == 50)
			(*all)->pla[w[0] + 1][w[1] - 1] = (*all)->posi + 1;
	}
	if (w[1] > 0 && w[1] < (*all)->big[1] - 1)
	{
		if ((*all)->pla[w[0]][w[1] + 1] == 50)
			(*all)->pla[w[0]][w[1] + 1] = (*all)->posi + 1;
		if ((*all)->pla[w[0]][w[1] - 1] == 50)
			(*all)->pla[w[0]][w[1] - 1] = (*all)->posi + 1;
	}
}

void		turn_to_rad(t_all **all)
{
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	while ((*all)->posi <= 50)
	{
		i[0] = 0;
		while (i[0] < (*all)->big[0])
		{
			i[1] = 0;
			while (i[1] < (*all)->big[1])
			{
				if ((*all)->pla[i[0]][i[1]] == (*all)->posi)
					lets_heat(&(*all), i);
				i[1]++;
			}
			i[0]++;
		}
		(*all)->posi++;
	}
}

void		fill(t_all **all)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while ((i = get_next_line(0, &line)))
	{
		j++;
		if (i == -1)
		{
			ft_putstr("ERROR ON LINE READ");
			return ;
		}
		if (ft_strstr(line, "Piece"))
		{
			create_piece(&(*all), line);
			map_checker(&(*all));
		}
		if (ft_strstr(line, "01234"))
			get_map(&(*all));
		ft_strdel(&line);
	}
	return ;
}
