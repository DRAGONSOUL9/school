/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 01:40:08 by oussama           #+#    #+#             */
/*   Updated: 2025/09/08 15:55:27 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_str(char *str, long x, size_t size, int sign)
{
	str[size--] = '\0';
	if (x == 0)
		str[size--] = '0';
	while (x != 0)
	{
		str[size] = (x % 10) + '0';
		x /= 10;
		size--;
	}
	if (sign == 1)
		str[size] = '-';
}

static size_t	ft_find_size(long x)
{
	size_t	size;

	size = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	x;
	size_t	size;
	char	*str;
	int		sign;

	x = (long)n;
	if (x > 2147483647 || x < -2147483648)
		return (NULL);
	sign = 0;
	if (x < 0)
	{
		sign = 1;
		x *= -1;
	}
	size = ft_find_size(x) + sign;
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	ft_fill_str(str, x, size, sign);
	return (str);
}
