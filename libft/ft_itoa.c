/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:06:53 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/13 15:35:28 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa(int n)
{
	char			*res;
	int				neg;
	unsigned int	i;

	neg = 0;
	i = ft_intlen(n);
	if (!(res = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (n < 0)
		neg = -1;
	else
		n = -n;
	res[i] = '\0';
	while (n < -9)
	{
		res[--i] = -(n % 10) + '0';
		n = n / 10;
	}
	res[--i] = -n + '0';
	if (neg == -1)
		res[0] = '-';
	return (res);
}
