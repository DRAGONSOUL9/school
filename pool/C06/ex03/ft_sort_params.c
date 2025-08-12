/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 08:33:47 by oel--mou          #+#    #+#             */
/*   Updated: 2025/07/28 09:28:54 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_print_param(int ac, char **av)
{
	int	i;
	int	v;

	v = 1;
	while (v < ac)
	{
		i = 0;
		while (av[v][i])
		{
			write (1, &av[v][i], 1);
			i++;
		}
		write (1, "\n", 1);
		v++;
	}
}

int	main(int ac, char **av)
{
	int		v1;
	int		v2;
	char	*tmp;

	v1 = 1;
	while (v1 < ac)
	{
		v2 = v1 + 1;
		while (v2 < ac)
		{
			if (ft_strcmp(av[v1], av[v2]) > 0)
			{
				tmp = av[v1];
				av[v1] = av[v2];
				av[v2] = tmp;
			}
			v2++;
		}
		v1++;
	}
	ft_print_param(ac, av);
	return (0);
}
