/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:54:44 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/26 20:03:58 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdint.h>

int				main(int argc, char** argv)
{
	t_array		tetris;
	t_field		field;
	t_field		*result;
	t_score		best_score;

	if (argc != 2)
	{
		ft_putstr("Usage: fillit TETROMINO_FILE\n");
		return (1);
	}
	best_score = INTPTR_MAX;
	if (read_file(&tetris, argv[1]) == false)
	{
		ft_putstr("Error: corrupted file\n");
		return (1);
	}
	field = init_field(16);
	result = fillit(&field, &tetris, &best_score);
	display_field(result);
	return (0);
}