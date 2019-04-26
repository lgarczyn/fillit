/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:58:29 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/15 19:13:59 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*trimmed_str;
	int		end;
	int		beg;
	int		tab_index;

	if (!s)
		return (NULL);
	end = ft_strlen(s);
	beg = 0;
	tab_index = 0;
	while (ft_iswhitespace(s[beg]))
		beg++;
	while (ft_iswhitespace(s[--end]))
		;
	if (!(trimmed_str = (char *)malloc(sizeof(char) * (end + 1))))
		return (NULL);
	while (beg <= end)
	{
		trimmed_str[tab_index] = s[beg];
		tab_index++;
		beg++;
	}
	trimmed_str[tab_index] = '\0';
	return (trimmed_str);
}
