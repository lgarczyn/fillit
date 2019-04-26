/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:45:52 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/26 19:55:30 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"
#include "libft.h"

/*
typedef enum		e_block
{
	b_empty = 0,
	b_filled = 1,
}					t_block;
*/

bool				read_tetri(int fd, t_tetri *out)
{
	t_block tetri;
	int		line_pos;
	int		line_count;
	char	**line;

	line_pos = 0;
	line_count_check(fd);
	while (line_count++ < 4)
	{
		get_next_line(fd, &line);
		while (line_pos < 4)
		{
			if (line[line_pos] == '.')
				out->data[line_count][line_pos] = b_empty;
			if (line[line_pos] == '#')
				out->data[line_count][line_pos] = b_used;
			if (line[4] != '\n')
			{
				free(line);
				return (false);
			}
		}
		line_count = 0;
	}
	return (true);
}
