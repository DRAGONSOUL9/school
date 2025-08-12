/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:59:29 by oel--mou          #+#    #+#             */
/*   Updated: 2025/07/29 10:33:09 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i >= 2)
		return (1);
	else
		return (0);
}

void	ft_print_nbr(long nbr, int b, char *base)
{
	if ((nbr / b) != 0)
		ft_print_nbr((nbr / b), b, base);
	write(1, &base[nbr % b], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		b;
	long	lnbr;

	b = ft_strlen(base);
	lnbr = nbr;
	if (ft_is_base_valid(base) == 0)
		return ;
	if (lnbr < 0)
	{
		write (1, "-", 1);
		lnbr *= -1;
	}
	ft_print_nbr(lnbr, b, base);
}
