/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:39:36 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/05/01 01:13:20 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void				display_usage(void)
{
	ft_putstr("Usage: fillit TETROMINO_FILE\n");
}

void				error(void)
{
	ft_putstr_fd("error\n", 1);
	exit(1);
}

void				display_field(const t_field *field)
{
	t_coord			x;
	t_coord			y;

	y = 0;
	while (y < field->score)
	{
		x = 0;
		while (x < field->score)
		{
			ft_putchar(field->blocks[y][x] ? 'A' + field->blocks[y][x] - 1
			: '.');
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}

void				display_solution(const t_array *tets, const t_pos *sol)
{
	t_field			field;
	t_coord			i;

	bzero(&field, sizeof(field));
	i = 0;
	while (i < tets->count)
	{
		write_field(&field, tets->tetris[i], sol[i], i + 1);
		i++;
	}
	display_field(&field);
}

void				display_tetri(const t_tetri *tetri)
{
	t_coord			x;
	t_coord			y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ft_putchar(tetri->data[y][x] ? '#' : '.');
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}
