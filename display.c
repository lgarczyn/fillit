/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:39:36 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/26 21:06:28 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void				display_usage(void)
{
	ft_putstr("Usage: fillit TETROMINO_FILE\n");
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
			ft_putchar(field->blocks[y][x] ? '#' : '.');
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
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
