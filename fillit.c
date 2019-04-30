/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:42:58 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/30 04:47:25 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

bool			next_pos(t_pos *pos)
{
	if (pos->y == 0)
	{
		pos->y = pos->x + 1;
		pos->x = 0;
		if (pos->y >= MAX_SCORE)
			return (false);
	}
	else if (pos->y > pos->x)
		pos->x++;
	else
		pos->y--;
	return (true);
}

void			fillit(const t_array *array, t_field *field, t_solution *solution, t_solution *best_solution, t_coord i)
{
	t_pos		pos;
	t_field		tmp;

	if (i == array->count)
	{
		solution->score = field->score;
		if (solution->score < best_solution->score)
			*best_solution = *solution;
		//handle absolute
		return ;
	}
	pos = (t_pos){0, 0};
	tmp = *field;
	do
	{
		if (write_field(field, array->tetris[i], pos) == false)
			continue;

		solution->positions[i] = pos;

		fillit(array, field, solution, best_solution, i + 1);
		
		*field = tmp;
	} while(next_pos(&pos));
}
