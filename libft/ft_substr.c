/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 01:36:22 by oussama           #+#    #+#             */
/*   Updated: 2025/09/19 03:45:39 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > (s_len - start))
		len = (s_len - start);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (len == 0)
		str[0] = '\0';
	else
		ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
