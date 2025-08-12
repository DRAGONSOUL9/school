/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:32:09 by oel--mou          #+#    #+#             */
/*   Updated: 2025/07/16 23:03:21 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_nbr(int n)
{
	char	c;

	c = n / 10 + '0';
	write (1, &c, 1);
	c = n % 10 + '0';
	write (1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	x;

	i = 0;
	while (i < 99)
	{
		x = i + 1;
		while (x < 100)
		{
			ft_print_nbr(i);
			write (1, " ", 1);
			ft_print_nbr(x);
			if (i != 98)
				write (1, ", ", 2);
			x++;
		}
		i++;
	}
}
