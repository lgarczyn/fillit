/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:54:44 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/30 04:48:12 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdint.h>

#include <stdio.h>

int				main(int argc, char **argv)
{
	t_array		tetris;
	
	t_field		*field;


	field = ft_memalloc(sizeof(t_field));
	

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
	*field = init_field();

	t_solution	state = {};
	t_solution	best_solution = {};

	best_solution.score = 255;

	fillit(&tetris, field, &state, &best_solution, 0);

	for (size_t i = 0; i < tetris.count; i++)
	{
		printf("%i %i\n", best_solution.positions[i].x, best_solution.positions[i].y);
	}

	return (0);
}
