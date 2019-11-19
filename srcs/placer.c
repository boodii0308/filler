/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:27:23 by tebatsai          #+#    #+#             */
/*   Updated: 2019/11/18 19:52:47 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

void		print(t_all **all)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(*all)->pla)
	{
		ft_putstr("ERROR ON LINE PLA");
		return ;
	}
	while (i != (*all)->big[0])
	{
		j = 0;
		while (j != (*all)->big[1])
		{
			ft_putnbr((*all)->pla[i][j]);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void		print2(t_all **all)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(*all)->lol)
	{
		ft_putstr("ERROR ON LINE PLA");
		return ;
	}
	while (i != (*all)->pc[0])
	{
		j = 0;
		while (j != (*all)->pc[1])
		{
			ft_putnbr((*all)->lol[i][j]);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void		dele(t_all **all)
{
	int		i;

	i = 0;
	if ((*all)->lol)
		dry_double(&(*all));
	while (i < (*all)->big[0])
	{
		free((*all)->pla[i]);
		i++;
	}
	free((*all)->pla);
	free((*all));
}
