/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:26:55 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/13 15:35:55 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_revstr(char *s)
{
	int				beg;
	int				end;
	char			tmp;

	beg = 0;
	end = ft_strlen(s) - 1;
	while (beg < end)
	{
		tmp = s[beg];
		s[beg] = s[end];
		s[end] = tmp;
		beg++;
		end--;
	}
	return (s);
}
