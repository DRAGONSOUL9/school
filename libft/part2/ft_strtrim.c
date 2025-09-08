/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 02:36:57 by oussama           #+#    #+#             */
/*   Updated: 2025/09/08 15:53:18 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_scan_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_find_size(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (ft_scan_set(s1[i], set) == 1)
		i++;
	while (s1[i])
	{
		i++;
		size++;
	}
	while (i > 0 && ft_scan_set(s1[--i], set) == 1)
		size--;
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	i2;
	size_t	size;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	size = ft_find_size(s1, set);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	while (ft_scan_set(s1[i], set) == 1)
		i++;
	i2 = 0;
	while (s1[i] && i2 < size)
		res[i2++] = s1[i++];
	res[i2] = '\0';
	return (res);
}
