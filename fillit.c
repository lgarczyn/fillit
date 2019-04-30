/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:42:58 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/30 23:17:52 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

bool		fill(t_array *tet_array, t_field *field, t_state *state, t_coord i)
{
	t_pos		pos;
	
	if (i == tet_array->count)
		return true;

	pos.y = 0;
	while (pos.y < state->size - tet_array->tetris[i].height)
	{
		pos.x = 0;
		while (pos.x < state->size - tet_array->tetris[i].width)
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
	{
		ret.size++;
	}
	return (ret);
}
