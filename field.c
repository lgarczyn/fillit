/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:11:51 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/05/08 12:25:25 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_field		init_field(void)
{
	t_field			f;

	ft_bzero(&f, sizeof(f));
	return (f);
}

bool		check_field(t_field *field, t_tetri tetri, t_pos pos)
{
	t_coord			x;
	t_coord			y;

	if (pos.x + tetri.width >= MAX_SCORE)
		return (false);
	if (pos.y + tetri.height >= MAX_SCORE)
		return (false);
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetri.data[y][x] && field->blocks[pos.y + y][pos.x + x])
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool		write_field(t_field *field, t_tetri tetri, t_pos pos, t_block value)
{
	t_coord			x;
	t_coord			y;

	if (check_field(field, tetri, pos) == false)
		return (false);
	y = 0;
	while (y < tetri.height)
	{
		x = 0;
		while (x < tetri.width)
		{
			if (tetri.data[y][x])
				field->blocks[pos.y + y][pos.x + x] = value;
			x++;
		}
		x = 0;
		y++;
	}
	field->score = ft_max(field->score,
		ft_max(pos.x + tetri.width, pos.y + tetri.height));
	return (true);
}

void		unwrite_field(t_field *field, t_tetri tetri, t_pos pos)
{
	t_coord			x;
	t_coord			y;

	y = 0;
	while (y < tetri.height)
	{
		x = 0;
		while (x < tetri.width)
		{
			if (tetri.data[y][x])
				field->blocks[pos.y + y][pos.x + x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
}
