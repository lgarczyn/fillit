/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 00:54:15 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/11 01:25:29 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_element;

	if (!(new_element = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new_element->content = NULL;
		new_element->content_size = 0;
	}
	else
	{
		if (!(new_element->content = (void *)malloc(sizeof(content_size))))
			return (NULL);
		ft_memcpy(new_element->content, content, content_size);
		new_element->content_size = content_size;
	}
	new_element->next = NULL;
	return (new_element);
}
