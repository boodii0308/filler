/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:27:37 by tebatsai          #+#    #+#             */
/*   Updated: 2019/11/18 20:03:41 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H
# include "../libft/libft.h"

typedef struct s_all	t_all;
struct					s_all
{
	int					big[2];
	int					pc[2];
	int					trig;
	int					posi;
	int					max;
	int					min;
	int					pos[4];
	char				p;
	int					**pla;
	int					**lol;
};
void					get_input(t_all **all, char *line, int j);
void					clean_up(t_all **all);
void					get_map(t_all **all);
void					lets_heat(t_all **all, int w[2]);
void					turn_to_rad(t_all **all);
void					fill(t_all **all);
void					print(t_all **all);
void					print2(t_all **all);
void					dele(t_all **all);
int						alid_the_move(t_all **all, int i[2], int x[2]);
int						olve_map(t_all **all, int x[2]);
void					map_checker(t_all **all);
void					get_player(t_all **all, char **s);
void					find_size(t_all *all, char *line, int *l);
void					create(t_all **all);
void					newin(t_all **all);
void					dry_double(t_all **all);
void					get_piece(t_all **all, char *line, int j);
void					put_lol(t_all **all);
void					create_piece(t_all **all, char *line);
#endif
