/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:29:46 by oel--mou          #+#    #+#             */
/*   Updated: 2025/08/03 16:11:03 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
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
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
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

int	ft_scan_base_for_c(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

long	ft_count_result(int len, int i, char *str, char *base)
{
	long	result;
	int		pos;

	result = 0;
	while (str[i])
	{
		pos = ft_scan_base_for_c(str[i], base);
		if (pos >= 0)
			result = (result * len) + (pos);
		else
			break ;
		i++;
	}
	return (result);
}
