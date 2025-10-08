/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:40:58 by oussama           #+#    #+#             */
/*   Updated: 2025/10/04 16:35:48 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long n, int base, int uppercase)
{
	char	*str;
	int	count;

	count = 0;
	if (uppercase > 0)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if ((n / base) != 0)
		count += ft_putnbr_base((n / base), base, uppercase);
	return (count + ft_putchar_fd(str[n % base], 1));
}
