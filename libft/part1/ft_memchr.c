/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 21:22:30 by oussama           #+#    #+#             */
/*   Updated: 2025/08/17 00:59:20 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	l;
	unsigned char	*p;

	l = (unsigned char)c;
	p = (unsigned char *)s;
	while (n > 0)
	{
		if (l == *p)
			return (p);
		p++;
		n--;
	}
	return (NULL);
}
