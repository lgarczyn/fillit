/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:18:17 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/13 13:55:18 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_concat;
	int		i;
	int		y;
	char	*str_concat;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	y = 0;
	len_concat = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(str_concat = (char *)malloc(sizeof(char) * len_concat)))
		return (NULL);
	while (s1[i])
	{
		str_concat[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		str_concat[i] = s2[y];
		i++;
		y++;
	}
	str_concat[i] = '\0';
	return (str_concat);
}
