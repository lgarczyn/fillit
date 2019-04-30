/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:54:44 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/30 23:49:25 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdint.h>

#include <stdio.h>

int				main(int argc, char **argv)
{
	t_array		tetris;
	t_state		state;

	if (argc != 2)
	{
		display_usage();
		return (1);
	}
	if (read_file(&tetris, argv[1]) == false)
		error();
	state = fillit(&tetris);
	display_solution(&tetris, state.positions);
	return (0);
}
