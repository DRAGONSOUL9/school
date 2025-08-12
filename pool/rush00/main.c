/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:48:47 by oel--mou          #+#    #+#             */
/*   Updated: 2025/07/20 15:56:44 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush(int x, int y);

int	main(void)
{
	rush (5, 3);
	ft_putchar('\n');
	rush (5, 1);
	ft_putchar('\n');
	rush (1, 1);
	ft_putchar('\n');
	rush (1, 5);
	ft_putchar('\n');
	rush (4, 4);
	ft_putchar('\n');
	rush (123, 42);
	ft_putchar('\n');
	rush (-5, 4);
	return (0);
}
