/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:20:51 by oel--mou          #+#    #+#             */
/*   Updated: 2025/08/05 06:53:33 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

void	ft_putnbr(int n)
{
	char	c;

	c = (n % 10) + '0';
	if ((n / 10) != 0)
		ft_putnbr(n / 10);
	write (1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;
	int	final;

	index = 0;
	final = 0;
	while ((par[final].str) != NULL)
		final++;
	while (index < final)
	{
		ft_putstr(par[index].str);
		ft_putnbr(par[index].size);
		write (1, "\n", 1);
		ft_putstr(par[index].copy);
		index++;
	}
}
