/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:40:50 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/13 13:56:49 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_w_count(char const *s, int c)
{
	unsigned int	i;
	unsigned int	in_or_out;
	unsigned int	w_count;

	i = 0;
	w_count = 0;
	in_or_out = OUT;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\0')
			in_or_out = OUT;
		if (in_or_out == OUT)
		{
			in_or_out = IN;
			w_count++;
		}
		i++;
	}
	return (w_count);
}

static char		*ft_cpy_inslot(char const *s, int c)
{
	char			*wrd;
	unsigned int	i;

	i = 0;
	wrd = NULL;
	if (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
		i++;
	if (!(wrd = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		wrd[i] = s[i];
		i++;
	}
	wrd[i] = '\0';
	return (wrd);
}

char			**ft_strsplit(char const *s, char c)
{
	char				**tab;
	unsigned int		w_count;
	unsigned int		tab_index;

	if (!s)
		return (NULL);
	tab_index = 0;
	w_count = ft_w_count(s, c);
	tab = NULL;
	if (!(tab = (char **)malloc(sizeof(char *) * (w_count + 1))))
		return (NULL);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && (*s != c))
		{
			tab[tab_index] = ft_cpy_inslot(s, c);
			tab_index++;
			while (*s && (*s != c))
				s++;
		}
	}
	tab[tab_index] = NULL;
	return (tab);
}
