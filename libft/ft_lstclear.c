/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 23:28:23 by oussama           #+#    #+#             */
/*   Updated: 2025/09/18 19:01:06 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	if (!lst || !del || !(*lst))
		return ;
	while ((*lst))
	{
		tmp = (*lst)->next;
		ft_lstdelone((*lst),del);
		(*lst) = tmp;
	}
}
