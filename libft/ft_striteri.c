/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:36:23 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/13 13:52:19 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int z;

	z = 0;
	if (s != NULL && f != NULL)
	{
		while (s[z])
		{
			f(z, &s[z]);
			z++;
		}
	}
}
