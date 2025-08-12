/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:21:43 by oel--mou          #+#    #+#             */
/*   Updated: 2025/07/31 20:17:18 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(unsigned char c, char *hex)
{
	write (1, "\\", 1);
	write (1, &hex[c / 16], 1);
	write (1, &hex[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			*hex;
	unsigned char	c;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i])
	{
		c = str[i];
		if (c < 32 || c >= 127)
			ft_print_hex(c, hex);
		else
			write(1, &c, 1);
		i++;
	}
}

int main(void)
{
	ft_putstr_non_printable("this is a test \n");
}
