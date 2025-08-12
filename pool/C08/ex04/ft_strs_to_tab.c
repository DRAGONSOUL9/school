/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:04:21 by oel--mou          #+#    #+#             */
/*   Updated: 2025/08/05 11:12:11 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i])
		i++;
	str = malloc (sizeof(char) * (i + 1));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			index;
	t_stock_str	*point;

	point = malloc (sizeof(t_stock_str) * (ac + 1));
	if (point == NULL)
		return (NULL);
	index = 0;
	while (index < ac)
	{
		point[index].size = ft_strlen(av[index]);
		point[index].str = av[index];
		point[index].copy = ft_strdup(av[index]);
		index++;
	}
	point[ac].str = NULL;
	return (point);
}
