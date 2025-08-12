/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 08:51:57 by oel--mou          #+#    #+#             */
/*   Updated: 2025/08/03 15:41:56 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_scan_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_str_size(char *str, char *charset, int *i)
{
	int	count;

	count = 0;
	while (str[*i] && ft_scan_charset(str[*i], charset) == 0)
	{
		count++;
		(*i)++;
	}
	return (count);
}

void	ft_find_word_size(char **arr, char *str, char *charset)
{
	int	i;
	int	i2;
	int	w;
	int	count;
	int	p_arr;

	i = 0;
	p_arr = 0;
	while (str[i])
	{
		w = i;
		count = ft_str_size(str, charset, &i);
		if (count > 0)
		{
			i2 = 0;
			arr[p_arr] = malloc(sizeof(char) * (count + 1));
			if (!arr[p_arr])
				return ;
			while (w < i)
				arr[p_arr][i2++] = str[w++];
			arr[p_arr++][i2] = '\0';
		}
		else
			i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		arr_size;
	char	**arr;

	i = 0;
	arr_size = 0;
	while (str[i])
	{
		if (ft_scan_charset(str[i], charset) == 0)
			if (i == 0 || ft_scan_charset(str[i - 1], charset) == 1)
				arr_size++;
		i++;
	}
	arr = malloc(sizeof (char *) * (arr_size + 1));
	if (!arr)
		return (NULL);
	if (arr_size > 0)
		ft_find_word_size(arr, str, charset);
	arr[arr_size] = NULL;
	return (arr);
}
