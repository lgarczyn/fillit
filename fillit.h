/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:41:37 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/30 05:17:34 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdbool.h>
# include <stdlib.h>
# include "types.h"

#define				MAX_SCORE 11
#define				MAX_TETRI 26

typedef enum		e_block
{
	b_empty = 0,
	b_filled = 1,
}					t_block;

typedef struct		s_pos
{
	t_coord			x;
	t_coord			y;
}					t_pos;

typedef struct		s_tetri
{
	t_block			data[4][4];
	t_coord			width;
	t_coord			height;
	bool			used;
}					t_tetri;

typedef struct		s_array
{
	t_tetri			tetris[MAX_TETRI];
	size_t			count;
}					t_array;

typedef struct		s_field
{
	t_block			blocks[MAX_SCORE][MAX_SCORE];
	t_coord			score;
}					t_field;

typedef struct		s_score
{
	t_coord			best;
	t_coord			worst;
	size_t			deviation;
}					t_score;

typedef struct		s_solution {
	t_pos			positions[MAX_TETRI];
	t_coord			score;
}					t_solution;

bool				read_tetri(int fd, t_tetri *out);
bool				validate_tetri(const t_tetri *tetri);
bool				read_file(t_array *out, char *name);

void				display_field(const t_field *field);
void				display_tetri(const t_tetri *tetri);
void				display_usage();

void				fillit(const t_array *array, t_field *field, t_solution *solution, t_solution *best_solution, t_coord i);

t_field				init_field();
bool				check_field(t_field *field, t_tetri tetri, t_pos pos);
bool				write_field(t_field *field, t_tetri tetri, t_pos pos);
void				unwrite_field(t_field *field, t_tetri tetri, t_pos pos);
#endif
