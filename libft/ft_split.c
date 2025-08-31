/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:31:31 by oussama           #+#    #+#             */
/*   Updated: 2025/08/25 20:37:03 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t ft_find_arr_size(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (
	}
}
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_find_arr_size(s,c);
}
