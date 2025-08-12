/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:37:28 by oel--mou          #+#    #+#             */
/*   Updated: 2025/07/28 22:04:43 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*arr;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	arr = malloc(sizeof(int) * (size));
	if (arr == NULL)
		return (NULL);
	while (i < size)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
