/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:13:13 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/16 20:03:43 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l_aux;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		l_aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = l_aux;
	}
}
