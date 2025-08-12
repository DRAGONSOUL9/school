/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:40:06 by oel--mou          #+#    #+#             */
/*   Updated: 2025/08/03 16:10:48 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *base);
int		ft_is_base_valid(char *base);
int		ft_scan_base_for_c(char c, char *base);
long	ft_count_result(int len, int i, char *str, char *base);

long	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	len;
	int	sign;

	len = ft_strlen(base);
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return ((ft_count_result(len, i, str, base)) * sign);
}

char	*ft_fill_nbr(long nbr, int b, char *base, int i)
{
	int		flag;
	char	*result;

	flag = 0;
	if (nbr < 0)
	{
		flag = 1;
		nbr *= -1;
		i++;
	}
	result = malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	result[i] = '\0';
	if (flag == 1)
		result[0] = '-';
	i--;
	while (i >= flag)
	{
		result[i] = base[nbr % b];
		nbr /= b;
		i--;
	}
	return (result);
}

char	*ft_putnbr_base(long nbr, char *base)
{
	int		b;
	int		i;
	long	tmp;
	long	lnbr;

	b = ft_strlen(base);
	lnbr = nbr;
	i = 1;
	tmp = lnbr;
	while ((tmp / b) != 0)
	{
		tmp /= b;
		i++;
	}
	return (ft_fill_nbr(lnbr, b, base, i));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	tmp;
	char	*result;

	if (ft_is_base_valid(base_from) == 0 || ft_is_base_valid(base_to) == 0)
		return (NULL);
	tmp = ft_atoi_base(nbr, base_from);
	if (tmp < -2147483648 || tmp > 2147483647)
		return (NULL);
	result = ft_putnbr_base(tmp, base_to);
	return (result);
}
