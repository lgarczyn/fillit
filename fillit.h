/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:41:37 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/04/27 02:47:20 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdbool.h>
# include <stdlib.h>
# include "types.h"

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
	t_tet_coord		width;
	t_tet_coord		height;
	bool			used;
}					t_tetri;

typedef struct		s_array
{
	t_tetri			*tetris;
	size_t			size;
	size_t			len;
}					t_array;

typedef struct		s_field
{
	t_block			**blocks;
	t_coord			size;
	t_score			score;
}					t_field;

bool				read_tetri(int fd, t_tetri *out);
bool				validate_tetri(const t_tetri *tetri);
bool				read_file(t_array *out, char *name);

t_score				score(const t_field *field);
t_field				*fillit(t_field *field, t_array *array, t_score *bst);

void				display_field(const t_field *field);
void				display_tetri(const t_tetri *tetri);
void				display_usage();

t_field				init_field();
void				free_field(t_field *field);
void				increase_field(t_field *field, size_t size);
bool				check_field(t_field *field, t_tetri tetri, t_pos pos);
bool				write_field(t_field *field, t_tetri tetri, t_pos pos);
#endif
