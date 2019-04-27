/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:11:51 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/27 02:53:38 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_field				init_field(size_t size)
{
	t_field			f;
	t_coord			i;
	t_block			*tmp;

	if (size == 0)
		size = 16;
	f.blocks = (t_block**)ft_xmalloc(size * sizeof(t_block*));
	tmp = (t_block*)ft_xmalloc(size * size * sizeof(t_block));
	i = 0;
	while (i < size)
	{
		f.blocks[i] = &tmp[i * size];
		i++;
	}
	f.size = size;
	return (f);
}

void				free_field(t_field *field)
{
	free(field->blocks[0]);
	ft_memdel((void**)&field->blocks);
}

void				increase_field(t_field *field, size_t size)
{
	t_coord			x;
	t_coord			y;
	t_field			tmp;

	if (size <= field->size)
		return ;
	tmp = init_field(size);
	y = 0;
	while (y < field->size)
	{
		x = 0;
		while (x < field->size)
		{
			tmp.blocks[y][x] = field->blocks[y][x];
			x++;
		}
		y++;
	}
	free_field(field);
	*field = tmp;
}

bool				check_field(t_field *field, t_tetri tetri, t_pos pos)
{
	t_coord			x;
	t_coord			y;

	increase_field(field, MAX(pos.x, pos.y) + MAX(tetri.height, tetri.width));
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

bool				write_field(t_field *field, t_tetri tetri, t_pos pos)
{
	t_coord			x;
	t_coord			y;

	if (check_field(field, tetri, pos) == false)
		return (false);
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			field->blocks[pos.y + y][pos.x + x] = tetri.data[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	field->score = MAX(field->score,
		MAX(pos.x + tetri.width, pos.y + tetri.height));
	return (true);
}
