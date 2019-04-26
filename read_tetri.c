/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:45:52 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/26 18:17:46 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"
#include "libft.h"

bool				read_tetri(int fd, t_tetri *out)
{
	int		line_counter;
	int		line_pos;
	int		touching;
	char	**line;

	line_counter = 0;
	line_pos = 0;
	while (get_next_line(fd, &line))
		line_counter++;
	if (line_counter > 3)
	{
		free(line);
		return (false);
	}
	free(line);
	while (line_counter++ < 4)
	{
		get_next_line(fd, &line);
		while (line_pos < 4)
		{
			if (line[3] != '\n' || line[line_pos] != '.' || line[line_pos] != '#')
			{
				free(line);
				return (false);
			}
			line_pos++;
		}
		line_pos = 0;
	}
}
