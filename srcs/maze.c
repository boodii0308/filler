/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:32:01 by tebatsai          #+#    #+#             */
/*   Updated: 2019/11/18 19:51:11 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int			valid_the_last(t_all **all, int i[2], int x[2])
{
	if (((*all)->lol[i[0]][i[1]] == 1)
	&& ((*all)->pla[x[0] + i[0]][x[1] + i[1]] >= 2
	|| (*all)->pla[x[0] + i[0]][x[1] + i[1]] == 0))
	{
		if ((*all)->pla[x[0] + i[0]][x[1] + i[1]] > 1)
			(*all)->max = (*all)->pla[x[0] + i[0]][x[1] + i[1]] < (*all)->max ?
				(*all)->pla[x[0] + i[0]][x[1] + i[1]] : (*all)->max;
		if ((*all)->max != (*all)->pla[x[0] + i[0]][x[1] + i[1]])
			(*all)->min++;
		else
			(*all)->min = 1;
		return (1);
	}
	return (0);
}

int			valid_the_move(t_all **all, int i[2], int x[2])
{
	if (x[0] + i[0] > (*all)->big[0] || x[1] + i[1] > (*all)->big[1])
		return (0);
	if (((*all)->lol[i[0]][i[1]] == -1)
	&& ((*all)->pla[x[0] + i[0]][x[1] + i[1]] >= 1
	|| (*all)->pla[x[0] + i[0]][x[1] + i[1]] == 0))
	{
		if ((*all)->pla[x[0] + i[0]][x[1] + i[1]] > 1)
			(*all)->max = (*all)->pla[x[0] + i[0]][x[1] + i[1]] < (*all)->max ?
				(*all)->pla[x[0] + i[0]][x[1] + i[1]] : (*all)->max;
		if ((*all)->max != (*all)->pla[x[0] + i[0]][x[1] + i[1]])
			(*all)->min++;
		else
			(*all)->min = 1;
		return (1);
	}
	if (((*all)->lol[i[0]][i[1]] == 1)
	&& ((*all)->pla[x[0] + i[0]][x[1] + i[1]] >= 2
	|| (*all)->pla[x[0] + i[0]][x[1] + i[1]] == 0))
	{
		return (valid_the_last(all, i, x));
	}
	return (0);
}

int			solve_map(t_all **all, int x[2])
{
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	(*all)->max = 50;
	(*all)->min = 1;
	while (i[0] < (*all)->pc[0] && i[1] < (*all)->pc[1]
	&& valid_the_move(&(*all), i, x))
	{
		if ((*all)->lol[i[0]][i[1]] == 1 &&
		(*all)->pla[x[0] + i[0]][x[1] + i[1]] == 0)
			i[2] += 1;
		i[1]++;
		if (i[1] == (*all)->pc[1])
		{
			i[0]++;
			if (i[2] == 1 && i[1] == (*all)->pc[1] && i[0] == (*all)->pc[0])
				return (1);
			i[1] = 0;
		}
	}
	return (0);
}

void		print_number(t_all **all)
{
	ft_putnbr((*all)->pos[0]);
	write(1, " ", 1);
	ft_putnbr((*all)->pos[1]);
	write(1, "\n", 1);
}

void		map_checker(t_all **all)
{
	int		i[2];

	i[0] = -1;
	while (++i[0] + (*all)->pc[0] <= (*all)->big[0])
	{
		i[1] = -1;
		while (++i[1] + (*all)->pc[1] <= (*all)->big[1])
		{
			if (solve_map(&(*all), i))
			{
				if (((*all)->pos[2] >= (*all)->max
				&& (*all)->pos[3] >= (*all)->min)
				|| (*all)->pos[2] >= (*all)->max)
				{
					(*all)->pos[0] = i[0];
					(*all)->pos[1] = i[1];
					(*all)->pos[2] = (*all)->max;
					(*all)->pos[3] = (*all)->min;
				}
			}
		}
	}
	print_number(&(*all));
}
