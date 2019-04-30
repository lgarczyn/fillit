/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <brjorgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:41:37 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/05/01 01:03:44 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdbool.h>
# include <stdlib.h>
# include "types.h"

# define MAX_SCORE 16
# define MAX_TETRI 26
# define TET_COUNT 19

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
	t_coord			id;
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

typedef struct		s_state
{
	t_pos			positions[MAX_TETRI];
	t_pos			highest_pos[TET_COUNT];
	t_coord			size;
}					t_state;

t_coord				get_ideal_score(t_array *array);
bool				read_tetri(int fd, t_tetri *out);
bool				read_file(t_array *out, char *name);
void				normalize_tetri(t_tetri *tetri);
bool				validate_tetri(const t_tetri *tetri);
void				id_tetri(t_tetri *tetri);

void				display_field(const t_field *field);
void				display_tetri(const t_tetri *tetri);
void				display_solution(const t_array *tets, const t_pos *sol);
void				display_usage();

t_state				fillit(t_array *tet_array);
void				error();

t_field				init_field();
bool				check_field(t_field *field, t_tetri tetri, t_pos pos);
bool				write_field(t_field *field, t_tetri tetri,
					t_pos pos, t_block val);
void				unwrite_field(t_field *field, t_tetri tetri, t_pos pos);
#endif
