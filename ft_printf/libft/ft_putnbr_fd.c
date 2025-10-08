/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:46:07 by oussama           #+#    #+#             */
/*   Updated: 2025/10/08 09:47:57 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr_fd("-2147483648", fd);
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		n *= -1;
	}
	if ((n / 10) != 0)
		count += ft_putnbr_fd((n / 10), fd);
	count += ft_putchar_fd(((n % 10) + '0'), fd);
	return (count);
}
