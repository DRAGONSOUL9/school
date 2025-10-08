/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 03:24:32 by oussama           #+#    #+#             */
/*   Updated: 2025/10/04 17:31:23 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int     ft_print_type(char c, va_list args)
{
        if (c == 'c')
                return (ft_putchar_fd(va_arg(args, int), 1));
        else if (c == 's')
                return (ft_putstr_fd(va_arg(args, char *), 1));
        else if (c == 'd' || c == 'i')
                return (ft_putnbr_fd(va_arg(args, int), 1));
        else if (c == 'x' || c == 'X')
                return (ft_putnbr_base((unsigned long)va_arg(args, unsigned int), 16, (c == 'X')));
        else if (c == 'u')
                return (ft_putnbr_base((unsigned long)va_arg(args, unsigned int), 10, 0));
        else if (c == 'p')
        {
                write (1 , "0x", 2);
                return (2 + ft_putnbr_base((unsigned long)va_arg(args, void *), 16, 0));
        }
        else if (c == '%')
                return ft_putchar_fd(c, 1);
        return (-1);
}

int	ft_printf(const char *str, ...)
{
	int	count;
	va_list	args;

	va_start(args, str);
	count = 0;
	while(*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_strchr("cspdiuxX%",*str))
				count += ft_print_type(*str, args);
			else
				return (-1);
		}
		else
			count += write (1 , str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
