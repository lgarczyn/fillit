/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:45:52 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/29 17:16:55 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"
#include "libft.h"

void				normalize_tetri(t_tetri *tetri) // work in progress
{
	t_pos		min_pos;
	t_pos		max_pos;
	t_coord		x;
	t_coord		y;

	min_pos = (t_pos){4, 4};
	max_pos = (t_pos){0, 0};
	x = 0;
	y = 0;
	while (y < 4)
	{
		if (tetri->data[y][x] == b_filled)
		{
			min_pos.x = MIN(x, min_pos.x);
			min_pos.y = MIN(y, min_pos.y);
			max_pos.x = MAX(x, max_pos.x);
			max_pos.y = MAX(y, max_pos.y);
		}
		x++;
		if (x == 4)
		{
			x == 0;
			y++;
		}
	}
	//shiftupleft
	tetri->width = max_pos.x - min_pos.x;
	tetri->height = max_pos.y - min_pos.y;
}

int					check_neighbours(t_pos pos, t_tetri *tetri)
{
	int count;

	count = 0;
	if (pos.x > 1 && tetri->data[pos.y][pos.x - 1])
		count++;
	if (pos.x < 3 && tetri->data[pos.y][pos.x + 1])
		count++;
	if (pos.y > 1 && tetri->data[pos.y - 1][pos.x])
		count++;
	if (pos.y < 3 && tetri->data[pos.y + 1][pos.x])
		count++;
	return (count);
}

bool				validate_tetri(const t_tetri *tetri)
{
	t_pos	*pos;
	int		ret;

	pos->x = 0;
	pos->y = 0;
	ret = 0;
	while (pos->y < 4)
	{
		if (tetri->data[pos->y][pos->x] == b_filled)
			ret += check_neighbours(*pos, tetri);
		pos->x++;
		if (pos->x == 4)
		{
			pos->x = 0;
			pos->y++;
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
			blocks[line_pos] = b_empty;
		else if (line[line_pos] == '#')
			blocks[line_pos] = b_filled;
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
	normalize_tetri(out);
	return (true);
}
