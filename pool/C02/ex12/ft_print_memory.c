/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:14:17 by oel--mou          #+#    #+#             */
/*   Updated: 2025/07/23 17:11:19 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_memory_address(unsigned long long fc_addr, char *hex)
{
	int		i;
	int		tmp;
	char	str[16];

	i = 15;
	while (i >= 0)
	{
		tmp = fc_addr % 16;
		str[i] = hex[tmp];
		i--;
		fc_addr /= 16;
	}
	write (1, str, 16);
	write (1, ": ", 2);
}

void	ft_print_hex(unsigned int p, char *str, char *hex, unsigned int size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (p >= size || str[p] == '\0')
		{
			write(1, "    ", 4);
			p += 2;
			i += 2;
		}
		else
		{
			write(1, &hex[(str[p] / 16)], 1);
			write(1, &hex[(str[p] % 16)], 1);
			write(1, &hex[(str[p + 1] / 16)], 1);
			write(1, &hex[(str[p + 1] % 16)], 1);
			i += 2;
			p += 2;
		}
		write(1, " ", 1);
	}
}

void	ft_print_text(unsigned int p, char *addr, unsigned int size)
{
	int	i;

	i = 0;
	while (i < 16 && p < size)
	{
		if (addr[p] >= 32 && addr[p] < 127)
		{
			write(1, &addr[p], 1);
		}
		else
		{
			write(1, ".", 1);
		}
		i++;
		p++;
	}
}

void	ft_strcpy(char *hex, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		hex[i] = src[i];
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned long long	c_addr;
	char				*str_addr;
	char				hex[16];

	i = 0;
	str_addr = (char *)addr;
	ft_strcpy(hex, "0123456789abcdef");
	if (size == 0)
		return (0);
	while (i < size)
	{
		c_addr = (unsigned long long)&str_addr[i];
		ft_print_memory_address(c_addr, hex);
		ft_print_hex(i, addr, hex, size);
		ft_print_text(i, addr, size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
