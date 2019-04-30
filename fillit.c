/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 01:23:58 by brjorgen          #+#    #+#             */
/*   Updated: 2019/05/01 01:26:03 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

bool		fill(t_array *tet_array, t_field *field, t_state *state, t_coord i)
{
	t_pos	pos;
	t_pos	max;

	if (i == tet_array->count)
		return (true);
	max.y = state->size - tet_array->tetris[i].height;
	max.x = state->size - tet_array->tetris[i].width;
	pos.y = 0;
	while (pos.y < max.y)
	{
		pos.x = 0;
		while (pos.x < max.x)
		{
			if (write_field(field, tet_array->tetris[i], pos, 1))
			{
				state->positions[i] = pos;
				if (fill(tet_array, field, state, i + 1))
					return (true);
				unwrite_field(field, tet_array->tetris[i], pos);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (false);
}

t_state		fillit(t_array *tet_array)
{
	t_field	field;
	t_state	ret;

	ft_bzero(&field, sizeof(field));
	ft_bzero(&ret, sizeof(ret));
	ret.size = get_ideal_score(tet_array);
	while (fill(tet_array, &field, &ret, 0) == false)
		ret.size++;
	return (ret);
}
