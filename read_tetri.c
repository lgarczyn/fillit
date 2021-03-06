/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:45:52 by brjorgen          #+#    #+#             */
/*   Updated: 2019/05/08 12:15:14 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"
#include "libft.h"

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
	if (validate_tetri(out) == false)
		return (false);
	normalize_tetri(out);
	return (true);
}
