/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:39:21 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/13 15:51:21 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	if (s1 == s2)
		return (1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	else
	{
		if (ft_strcmp(s1, s2) != 0)
			return (0);
		else
			return (1);
	}
}
