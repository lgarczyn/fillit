/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:19:39 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/08 18:48:01 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	stop;
	unsigned char	*casted_d;
	const char		*casted_s;

	casted_d = dest;
	casted_s = src;
	stop = c;
	while (n--)
		if ((*casted_d++ = *casted_s++) == stop)
			return (casted_d);
	return (NULL);
}
