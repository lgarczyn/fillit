/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 08:23:53 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/15 19:09:47 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	long int			s;
	long long int		n;

	s = 1;
	n = 0;
	while (ft_iswhitespace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		s = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		n = (n * 10) + (*nptr - 48);
		if (0 > n)
			return (s == -1 ? 0 : -1);
		nptr++;
	}
	return (s * n);
}
