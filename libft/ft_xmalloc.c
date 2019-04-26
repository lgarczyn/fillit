/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:48:52 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/26 17:51:07 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

void	*ft_xmalloc(size_t size)
{
	void *tmp;

	if (!size || !(tmp = malloc(size)))
	{
		ft_putstr_fd("Fatal error: Failed to allocate memory.\n", 2);
		exit(ENOMEM);
	}
	ft_bzero(tmp, size);
	return (tmp);
}
