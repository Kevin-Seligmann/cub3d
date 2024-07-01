/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:37:56 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/17 18:14:46 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*local_free(t_list *l, void *content, void (*del)(void *))
{
	ft_lstclear(&l, del);
	del(content);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l_head;
	t_list	*l_tail;
	void	*content;

	if (!f || !del || !lst)
		return (0);
	content = f(lst->content);
	lst = lst->next;
	l_head = ft_lstnew(content);
	if (!l_head)
	{
		del(content);
		return (0);
	}
	l_tail = l_head;
	while (lst)
	{
		content = f(lst->content);
		lst = lst->next;
		l_tail->next = ft_lstnew(content);
		l_tail = l_tail->next;
		if (!l_tail)
			return (local_free(l_head, content, del));
	}
	return (l_head);
}
