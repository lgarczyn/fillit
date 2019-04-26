/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:11:14 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/12 17:33:07 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	unsigned char stop;

	stop = c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == stop)
			return ((void *)str);
		str++;
	}
	return (NULL);
}

/*
**	void	*ft_memchr(const void *s, int c, size_t n)
**	{
**		unsigned char *str;
**		unsigned char stop;
**
**		stop = c;
**		str = (unsigned char *)s;
**		while (str && n--)
**		{
**			if (*str == stop)
**				return ((void *)str);
**			str++;
**		}
**		return (NULL);
**	}
*/
