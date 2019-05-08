/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:21:33 by lgarczyn          #+#    #+#             */
/*   Updated: 2019/05/08 12:26:57 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord				ft_min(t_coord a, t_coord b)
{
	return (a < b ? a : b);
}

t_coord				ft_max(t_coord a, t_coord b)
{
	return (a > b ? a : b);
}

t_pos				ft_max_pos(t_pos a, t_pos b)
{
	t_pos			out;

	out.x = (a.x > b.x) ? a.x : b.x;
	out.y = (a.y > b.y) ? a.y : b.y;
	return (out);
}

t_pos				ft_min_pos(t_pos a, t_pos b)
{
	t_pos			out;

	out.x = (a.x < b.x) ? a.x : b.x;
	out.y = (a.y < b.y) ? a.y : b.y;
	return (out);
}
