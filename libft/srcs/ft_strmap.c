/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:14:51 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/08 12:44:43 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	item;
	char			*tab;

	item = 0;
	tab = NULL;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(tab = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[item])
	{
		tab[item] = (*f)(s[item]);
		item++;
	}
	tab[item] = '\0';
	return (tab);
}
