/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:12:35 by tebatsai          #+#    #+#             */
/*   Updated: 2019/11/18 19:35:50 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

void		get_player(t_all **all, char **s)
{
	char	*c;

	(*all)->big[0] = 0;
	(*all)->big[1] = 0;
	c = *s;
	if (ft_strstr(c, "p1"))
		(*all)->p = 'o';
	else if (ft_strstr(c, "p2"))
		(*all)->p = 'x';
}

void		find_size(t_all *all, char *line, int *l)
{
	int		i;
	int		e;

	i = 0;
	e = 0;
	(void)*all;
	while (line[i] && (l[0] == 0 || l[1] == 0))
	{
		if (ft_isdigit(line[i]) && e == 0)
		{
			l[0] = ft_atoi(&line[i]);
			while (ft_isdigit(line[i]))
				i++;
			e = 1;
		}
		if (ft_isdigit(line[i]) && e == 1)
			l[1] = ft_atoi(&line[i]);
		i++;
	}
	return ;
}

void		create(t_all **all)
{
	int		i;

	i = 0;
	(*all)->posi = 1;
	(*all)->max = 50;
	(*all)->pos[0] = 0;
	(*all)->pos[1] = 0;
	(*all)->pos[2] = 50;
	(*all)->pos[3] = 50;
	(*all)->pc[0] = 0;
	(*all)->pc[1] = 0;
	(*all)->pla = (int **)malloc(sizeof(int*) * (*all)->big[0]);
	while (i < (*all)->big[0])
	{
		(*all)->pla[i] = (int *)malloc(sizeof(int) * (*all)->big[1]);
		i++;
	}
}

void		newin(t_all **all)
{
	int		i;
	int		j;
	char	*line;

	(*all)->p = '\0';
	(*all)->trig = 0;
	i = 0;
	while (i < 10 && (j = get_next_line(0, &line)))
	{
		if (j == -1)
		{
			ft_putstr("ERROR ON LINE READ");
			return ;
		}
		if ((*all)->p == '\0' && ft_strstr(line, "tebatsai"))
			get_player(&(*all), &line);
		if (ft_strstr(line, "Plateau"))
		{
			find_size((*all), line, &(*(*all)->big));
			return ;
		}
		i++;
		ft_strdel(&line);
	}
	return ;
}

int			main(void)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	newin(&all);
	create(&all);
	get_map(&all);
	fill(&all);
	dele(&all);
	return (0);
}
