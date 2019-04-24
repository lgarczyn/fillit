/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:30:53 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/13 14:42:15 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*cas1;
	unsigned char	*cas2;

	cas1 = (unsigned char *)s1;
	cas2 = (unsigned char *)s2;
	i = 0;
	while ((cas1[i] && cas2[i]) && (cas1[i] == cas2[i]) && i < n)
		i++;
	if (i == n)
		return (0);
	return (cas1[i] - cas2[i]);
}
