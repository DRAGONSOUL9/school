/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 03:24:32 by oussama           #+#    #+#             */
/*   Updated: 2025/10/08 15:26:14 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
//added this line to test the push script
typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int width;
} t_flags;

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

static int	ft_padding(char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write (1, &c, 1);
		i++;
	}
	return (i);
}

static int	ft_specialneeds(char c, va_list args, t_flags *flags)
{
	int	writen;

	writen = 0;
	if (flags->minus == 1)
		writen = ft_print_type(c, args);
	if (flags->zero == 1 && flags->minus != 1)
		writen += ft_padding('0', (flags->width - writen));
	else
		writen += ft_padding(' ', (flags->width - writen));
	return (writen);
}

static int	ft_flags_parser(const char *str, t_flags *flags)
{
	size_t	i;

	i = 0;
	flags->minus = 0;
    flags->zero = 0;
    flags->dot = 0;
    flags->width = 0;
	while (*str && (ft_strchr("-0.",*str) || ft_isdigit(*str)))
	{
		if (*str == '-')
		{
			flags->minus = 1;
			flags->zero = 0;
		}
		else if (*str == '0' && flags->minus != 1)
			flags->zero = 1;
		else if (*str == '.')
			flags->dot = 1;
		else if (ft_isdigit(*str))
			flags->width = (10 * flags->width) + (*str - '0');
		str++;
		i++;
	}
	return (i);
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
			else if (ft_strchr("-0.#+",*str) || ft_isdigit(*str))
			{
				t_flags flags;
				str += ft_flags_parser(str, &flags);
				count += ft_specialneeds(*str, args, &flags);
			}
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
