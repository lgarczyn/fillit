/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 00:07:52 by brjorgen          #+#    #+#             */
/*   Updated: 2019/05/08 12:26:06 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"
#include "libft.h"

void				shift_tetri(t_tetri *tetri, t_pos min_pos)
{
	t_coord		x;
	t_coord		y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		if (x < 4 - min_pos.x && y < 4 - min_pos.y)
			tetri->data[y][x] = tetri->data[y + min_pos.y][x + min_pos.x];
		else
			tetri->data[y][x] = 0;
		x++;
		if (x == 4)
		{
			x = 0;
			y++;
		}
	}
}

void				normalize_tetri(t_tetri *tetri)
{
	t_pos		min_pos;
	t_pos		max_pos;
	t_pos		pos;

	min_pos = (t_pos){4, 4};
	max_pos = (t_pos){0, 0};
	pos = (t_pos){0, 0};
	while (pos.y < 4)
	{
		if (tetri->data[pos.y][pos.x])
		{
			min_pos = ft_min_pos(min_pos, pos);
			max_pos = ft_max_pos(max_pos, pos);
		}
		pos.x++;
		if (pos.x == 4)
		{
			pos.x = 0;
			pos.y++;
		}
	}
	shift_tetri(tetri, min_pos);
	tetri->width = max_pos.x - min_pos.x + 1;
	tetri->height = max_pos.y - min_pos.y + 1;
}

int					count_neighbours(t_pos pos, const t_tetri *tetri)
{
	int count;

	count = 0;
	if (pos.x > 0 && tetri->data[pos.y][pos.x - 1])
		count++;
	if (pos.x < 3 && tetri->data[pos.y][pos.x + 1])
		count++;
	if (pos.y > 0 && tetri->data[pos.y - 1][pos.x])
		count++;
	if (pos.y < 3 && tetri->data[pos.y + 1][pos.x])
		count++;
	return (count);
}

bool				validate_tetri(const t_tetri *tetri)
{
	t_pos	pos;
	int		ret;

	pos.x = 0;
	pos.y = 0;
	ret = 0;
	while (pos.y < 4)
	{
		if (tetri->data[pos.y][pos.x])
			ret += count_neighbours(pos, tetri);
		pos.x++;
		if (pos.x == 4)
		{
			pos.x = 0;
			pos.y++;
		}
	}
	return ((ret == 6 || ret == 8) ? true : false);
}
