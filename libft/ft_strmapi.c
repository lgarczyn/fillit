/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:50:18 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/08 12:44:21 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	item;
	char			*tab;

	item = 0;
	if (!(s == NULL && f == NULL))
	{
		if (!(tab = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (s[item])
		{
			tab[item] = f(item, s[item]);
			item++;
		}
		tab[item] = '\0';
		return (tab);
	}
	return (NULL);
}
