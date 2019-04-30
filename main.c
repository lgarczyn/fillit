/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:54:44 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/30 07:12:55 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdint.h>

#include <stdio.h>

int				main(int argc, char **argv)
{
	t_array		tetris;
	t_field		field;
	t_state		state;

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
	
	bzero(&field, sizeof(t_field));
	bzero(&state, sizeof(state));
	state.best_possible_score = get_ideal_score(&tetris);
	state.solution_score = 255;

	fillit(&tetris, &field, &state, 0);

	for (size_t i = 0; i < tetris.count; i++)
	{
		printf("%i %i\n", state.solution[i].x, state.solution[i].y);
	}

	return (0);
}
