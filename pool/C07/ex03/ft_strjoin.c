/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:33:10 by oel--mou          #+#    #+#             */
/*   Updated: 2025/08/03 16:23:12 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_fill_result(char **strs, char *sep, char *result, int size)
{
	int	x;
	int	i;
	int	r;

	x = 0;
	r = 0;
	while (x < size)
	{
		i = 0;
		while (strs[x][i])
			result[r++] = strs[x][i++];
		i = 0;
		while (sep[i] && x < size -1)
			result[r++] = sep[i++];
		x++;
	}
	result[r] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		x;
	char	*result;

	len = 0;
	x = 0;
	if (size == 0)
	{
		result = malloc(1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	while (x < size)
	{
		len += ft_strlen(strs[x++]);
	}
	len += (ft_strlen(sep) * (size -1));
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_fill_result(strs, sep, result, size);
	return (result);
}
