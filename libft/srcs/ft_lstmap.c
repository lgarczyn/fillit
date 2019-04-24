/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:23:00 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/13 15:37:17 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*filtered_elem;
	t_list		*new_list;

	if (!lst)
		return (NULL);
	filtered_elem = ft_lstnew(lst->content, lst->content_size);
	filtered_elem = f(lst);
	new_list = filtered_elem;
	while (lst->next)
	{
		new_list->next = f(lst->next);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (filtered_elem);
}
