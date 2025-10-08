/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 17:23:35 by oussama           #+#    #+#             */
/*   Updated: 2025/10/04 17:26:06 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int     a;
        int     b;
        char    c = 'A';
        char    *s = "Hello";
        int     x = 42;

        a = ft_printf("x = 3 * 2 = %d\n", x);
        b = printf("x = 3 * 2 = %d\n", x);
        ft_printf("a = %d       b = %d\n\n",a,b);
        
        a = ft_printf("int max is : %d\n", 2147483647);
        b = printf("int max is : %d\n", 2147483647);
        ft_printf("a = %d       b = %d\n\n",a,b);
        
        a = ft_printf("int min is : %d\n", INT_MIN);
        b = printf("int min is : %d\n", INT_MIN);
        ft_printf("a = %d       b = %d\n\n",a,b);
        
        a = ft_printf("HEX max is : %X\n", 2147483647);
        b = printf("HEX max is : %X\n", 2147483647);
        ft_printf("a = %d       b = %d\n\n",a,b);
        
        a = ft_printf("HEX min is : %X\n", INT_MIN);
        b = printf("HEX min is : %X\n", INT_MIN);
        ft_printf("a = %d       b = %d\n\n",a,b);
        
        a = ft_printf("HEX min is : %X\n", -1);
        b = printf("HEX min is : %X\n", -1);
        ft_printf("a = %d       b = %d\n\n",a,b);
        
        a = ft_printf("unsigned int max is : %u\n", 4294967295u);
        b = printf("unsigned int max is : %u\n", 4294967295u);
        ft_printf("a = %d       b = %d\n\n",a,b);

        a = ft_printf("should print 0 = %d\n", 0);
        b = printf("should print 0 = %d\n", 0);
        ft_printf("a = %d       b = %d\n\n",a,b);
        
        a = ft_printf("should print \"test\" : %s %d \n", "test", 1998);
        b = printf("should print \"test\" : %s %d \n", "test", 1998);
        ft_printf("a = %d       b = %d\n\n",a,b);

        a = ft_printf("memory address of x is : %p\n", &a);
        b = printf("memory address of x is : %p\n", &a);
        ft_printf("a = %d       b = %d\n\n", a, b);

        a = ft_printf("ft_printf: %p %d %i %u %x %X %s %c %%\n", &x, 123, -123, 4294967295u, 255, 255, s, c);
        b = printf("printf:    %p %d %i %u %x %X %s %c %%\n", &x, 123, -123, 4294967295u, 255, 255, s, c);
        printf("ft_printf len = %d | printf len = %d\n", a, b);
}
