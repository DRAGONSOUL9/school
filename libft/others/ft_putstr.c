/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:54:53 by oel--mou          #+#    #+#             */
/*   Updated: 2025/09/08 20:04:57 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "this is ft_putstr and this message shows if the string is NULL\n", 63);
		return ;
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	write (1, &c, 1);
}
