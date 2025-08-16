/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 21:58:03 by oussama           #+#    #+#             */
/*   Updated: 2025/08/16 22:23:00 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	i2;
	size_t	p;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		i2 = 0;
		p = i;
		while (big[p] && little[i2] && p < len && big[p] == little[i2])
		{
			p++;
			i2++;
		}
		if (little[i2] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
