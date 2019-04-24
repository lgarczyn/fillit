/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 00:55:01 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/08 18:49:16 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alist, void (*del)(void *, size_t))
{
	if (!(alist || del))
		return ;
	del((*alist)->content, (*alist)->content_size);
	free(*alist);
	*alist = NULL;
}
