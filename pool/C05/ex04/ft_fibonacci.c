/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:10:14 by oel--mou          #+#    #+#             */
/*   Updated: 2025/07/28 12:02:54 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_nth(int index, int n1, int n2)
{
	int	n3;

	n3 = n1 + n2;
	if ((index - 1) >= 0)
		n3 = ft_find_nth((index - 1), n2, n3);
	return (n3);
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0 || index == 1)
		return (index);
	return (ft_find_nth((index - 2), 0, 1));
}
