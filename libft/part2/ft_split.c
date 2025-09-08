/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:31:31 by oussama           #+#    #+#             */
/*   Updated: 2025/09/08 15:51:21 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_arr(char **arr, size_t index)
{
	while (index > 0)
	{
		free(arr[index - 1]);
		index--;
	}
	free(arr);
}

static size_t	ft_find_arr_size(char const *s, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (i == 0 && (s[i + 1] != '\0' || s[i + 1] != c))
			size++;
		else if (s[i] == c && s[i - 1] != c)
			size++;
		i++;
	}
	return (size);
}

static size_t	ft_word_size(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_fill_arr(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	index;
	size_t	w_size;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			w_size = ft_word_size(&s[i], c);
			arr[index] = malloc (w_size + 1);
			if (!arr[index])
			{
				ft_free_arr(arr, index);
				return (NULL);
			}
			ft_strlcpy(arr[index++], &s[i], w_size + 1);
			i += w_size;
		}
		else
			i++;
	}
	arr[index] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**arr;

	if (!s)
		return (NULL);
	size = ft_find_arr_size(s, c);
	arr = malloc (sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	if (!ft_fill_arr(s, c, arr))
		return (NULL);
	return (arr);
}
