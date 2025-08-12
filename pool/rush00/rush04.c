/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhiyli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:30:33 by nouhiyli          #+#    #+#             */
/*   Updated: 2025/07/20 15:47:46 by nouhiyli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_newline(int y, int j)
{
	if (j <= y)
		ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (x <= 0 || y <= 0)
		return ;
	while (j <= y)
	{
		i = 1;
		while (i <= x)
		{
			if ((i == 1 && j == 1) || (i == x && j == y && x != 1 && y != 1))
				ft_putchar('A');
			else if ((i == 1 && j == y) || (i == x && j == 1))
				ft_putchar('C');
			else if (j == 1 || j == y || i == 1 || i == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
			i++;
		}
		print_newline(y, j);
		j++;
	}
}
