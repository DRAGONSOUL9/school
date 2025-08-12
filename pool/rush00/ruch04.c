/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruch04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:21:09 by oel--mou          #+#    #+#             */
/*   Updated: 2025/07/20 18:54:29 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	h;
	int	v;

	v = 1;
	if ((x <= 0) || (y <= 0))
		return ;
	while (v <= y)
	{
		h = 1;
		while(h <= x)
		{
			if ((h == 1 && v == 1) || (h == x && v == y && x != 1 && y != 1))
				ft_putchar('A');
			else if ((h == x && v == 1) || (h == 1 && v == y))
				ft_putchar('C');
			else if ( v == 1 || h == 1 || h == x || v == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			h++;
		}
		ft_putchar('\n');
		v++;
	}

}
