/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:42:02 by oussama           #+#    #+#             */
/*   Updated: 2025/08/14 15:36:30 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*p_dest;
	const char		*p_src;

	p_dest = (char *)dest;
	p_src = (const char *)src;
	i = 0;
	if (p_src > p_dest)
	{
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	else if (p_src < p_dest)
	{
		while (i < n)
		{
			p_dest[(n - 1) - i] = p_src[(n - 1) - i];
			i++;
		}
	}
	return (dest);
}
