/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:45:52 by brjorgen          #+#    #+#             */
/*   Updated: 2019/05/01 00:05:31 by brjorgen         ###   ########.fr       */
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
	t_pos		coord;

	min_pos = (t_pos){4, 4};
	max_pos = (t_pos){0, 0};
	coord.x = 0;
	coord.y = 0;
	while (coord.y < 4)
	{
		if (tetri->data[coord.y][coord.x])
		{
			min_pos.x = MIN(coord.x, min_pos.x);
			min_pos.y = MIN(coord.y, min_pos.y);
			max_pos.x = MAX(coord.x, max_pos.x);
			max_pos.y = MAX(coord.y, max_pos.y);
		}
		coord.x++;
		if (coord.x == 4)
		{
			coord.x = 0;
			coord.y++;
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

bool				read_line(char *line, t_block *blocks)
{
	int		line_pos;

	line_pos = -1;
	while (++line_pos < 4)
	{
		if (line[line_pos] == '.')
			blocks[line_pos] = 0;
		else if (line[line_pos] == '#')
			blocks[line_pos] = 1;
		else
			return (false);
	}
	if (line[4] != '\0')
		return (false);
	return (true);
}

bool				read_tetri(int fd, t_tetri *out)
{
	int		line_count;
	char	*line;
	bool	res;

	line_count = -1;
	while (++line_count < 4 && get_next_line(fd, &line) > 0)
	{
		res = read_line(line, (out->data[line_count]));
		free(line);
		if (res == false)
			return (false);
	}
	if (line_count != 4)
		return (false);
	out->used = false;
	if (validate_tetri(out))
		normalize_tetri(out);
	else
		return (false);
	return (true);
}
