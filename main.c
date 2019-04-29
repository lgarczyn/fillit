/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:54:44 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/29 20:30:30 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdint.h>

int				main(int argc, char **argv)
{
	t_array		tetris;
	t_field		field;

	if (argc != 2)
	{
		display_usage();
		return (1);
	}
	if (read_file(&tetris, argv[1]) == false)
	{
		ft_putstr("Error: corrupted file\n");
		return (1);
	}
	field = init_field(16);

	for (size_t i = 0; i < tetris.count; i++)
	{
		display_tetri(&tetris.tetris[i]);
		write_field(&field, tetris.tetris[i], (t_pos){i * 4, 0});
		ft_putstr("\n");
	}
	display_field(&field);

	//result = fillit(&field, &tetris, &best_score);
	//display_field(result);
	return (0);
}
