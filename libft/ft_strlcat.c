/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:52:28 by oussama           #+#    #+#             */
/*   Updated: 2025/08/16 18:05:19 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;
	size_t	s_len;
	size_t	d_len;

	s_len = 0;
	while (src[s_len])
		s_len++;
	if (size < s_len)
                return (size + s_len);
	d_len = 0;
	while (dst[d_len])
		d_len++;
	i = 0;
	i2 = d_len;
	while (src[i] && i2 < (size - 1))
		dst[i2] = src[i++];
	dst[i2] = '\0';
	return (d_len + s_len);
}
