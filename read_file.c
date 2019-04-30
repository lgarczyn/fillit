/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:45:52 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/30 07:16:22 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"
#include "libft.h"

int					check_endline(int fd)
{
	char			*line;
	int				res;

	res = get_next_line(fd, &line);
	if (res <= 0 || line[0] != '\0')
	{
		free(line);
		return (res == 0 ? 0 : -1);
	}
	free(line);
	return (1);
}

void				push_tetri(t_array *array, t_tetri tetri)
{
	array->tetris[array->count++] = tetri;
}

bool				read_file(t_array *out, char *name)
{
	int				fd;
	t_tetri			tmp;
	int				res;

	ft_bzero(out, sizeof(t_array));
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		ft_putstr_fd("Error: failed to open file.", 2);
		return (false);
	}
	if (read_tetri(fd, &tmp) == false)
		return (false);
	push_tetri(out, tmp);
	while (1)
	{
		res = check_endline(fd);
		if (res == 0)
			return (true);
		if (res == -1)
			return (false);
		if (out->count >= MAX_TETRI)
			return (false);
		if (read_tetri(fd, &tmp) == false)
			return (false);
		push_tetri(out, tmp);
	}
}

t_uint			sqrt_ceil (t_uint n) {

	t_uint		result;
	t_uint		square;

	result = 0;
	square = 0;
	while (square < n) {
		square += (result * 2 + 1);
		result++;
	}
	return result;
}

t_coord			get_ideal_score(t_array *array)
{
	return (sqrt_ceil(array->count * 4));
}
