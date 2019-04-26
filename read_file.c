/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:45:52 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/27 00:35:28 by lgarczyn         ###   ########.fr       */
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

void				ft_realloc(t_tetri **ptr, size_t old_size, size_t new_size)
{
	t_tetri			*tmp;

	if (old_size > new_size)
		return ;
	tmp = ft_xmalloc(sizeof(t_tetri) * new_size);
	ft_memcpy(tmp, *ptr, old_size * sizeof(t_tetri));
	*ptr = tmp;
}

void				push_tetri(t_array *array, t_tetri tetri)
{
	size_t			new_size;

	if (array->len >= array->size)
	{
		new_size = array->size ? array->size * 2 : 16;
		ft_realloc(&array->tetris, array->size, new_size);
		array->size = new_size;
	}
	array->tetris[array->len++] = tetri;
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
		if (read_tetri(fd, &tmp) == false)
			return (false);
		push_tetri(out, tmp);
	}
}
