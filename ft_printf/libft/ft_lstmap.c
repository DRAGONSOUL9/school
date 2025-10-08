/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:16:00 by oussama           #+#    #+#             */
/*   Updated: 2025/09/19 04:14:44 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lsthead;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	lsthead = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&lsthead, del);
			return (NULL);
		}
		ft_lstadd_back(&lsthead, tmp);
		lst = lst->next;
	}
	return (lsthead);
}
