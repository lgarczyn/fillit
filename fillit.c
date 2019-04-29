/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:42:58 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/30 01:22:28 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

typedef struct	s_solution {
	t_pos		positions[MAX_TETRI];
	t_coord		score;
}				t_solution;

bool	next_pos(t_pos *pos)
{

}

//t_solution fillit(field, tetris, *solution, i)
//{
//	t_solution best_solution;
//
//	best_solution.score = MAX_SCORE;
//
//	if (i == tetris.count)
//	{
//		solution.score = field.score;
//		return solution;
//	}
//
//	for each pos
//
//		if (write_field(&field, &tetris[i], pos) == false)
//			continue;
//
//		solution[i] = pos;
//
//		t_solution s = fillit(solution, field, tetris, i + 1)
//
//		if (s.score < best_solution.score)
//			best_solution = s;
//		
//		unwrite_field(&field, &tetris[i], pos);
//
//	return best_solution;
//}
