/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:42:58 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/30 03:08:49 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

typedef struct	s_solution {
	t_pos		positions[MAX_TETRI];
	t_coord		score;
}				t_solution;

bool	next_pos(t_pos *pos)
{
	if (pos->x >= 11 || pos->y >= 11)
		return (false);
	if (pos->y == 0)
	{
		pos->y = pos->x + 1;
		pos->x = 0;
	}
	else if (pos->y > pos->x)
		pos->x++;
	else
		pos->y--;
	return (true);
}