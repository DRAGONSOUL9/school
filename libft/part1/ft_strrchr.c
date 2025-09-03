/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:00:01 by oussama           #+#    #+#             */
/*   Updated: 2025/08/16 20:16:39 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	p;

	i = 0;
	p = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			p = i;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	if (p > -1)
		return ((char *)&s[p]);
	return (NULL);
}
