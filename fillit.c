/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:42:58 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/30 21:02:44 by lgarczyn         ###   ########.fr       */
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

void			fillit(const t_array *array, t_field *field, t_state *state, t_coord i)
{
	t_pos		pos;
	t_coord		old_score;

	if (field->score >= state->solution_score)
		return;
	if (i == array->count)
	{
		if (field->score < state->solution_score)
		{
			ft_memcpy(state->solution, state->positions, array->count * sizeof(t_pos));
			state->solution_score = field->score;
			ft_putstr("best solution\n");
			display_field(field);
		}
		return ;
	}
	pos = (t_pos){0, 0};
	old_score = field->score;
	do
	{
		if (write_field(field, array->tetris[i], pos, 1) == false)
			continue;

		state->positions[i] = pos;

		fillit(array, field, state, i + 1);
		
		unwrite_field(field, array->tetris[i], pos);
		field->score = old_score;

		if (state->solution_score == state->best_possible_score)
			return;
	} while(next_pos(&pos));
}
