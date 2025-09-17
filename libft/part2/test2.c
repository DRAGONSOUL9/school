/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:10:32 by oussama           #+#    #+#             */
/*   Updated: 2025/09/12 12:14:40 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

static void	ft_print_double_arr(char **arr)
{
	int	index;

	index = 0;
	if (!arr)
	{
		printf("error occured the arr returned NULL\n");
		return;
	}
	while (arr[index])
		printf("%s\n",arr[index++]);
}

void	test_part_2(void)
{
	int	i = 0;
	//ft_split
	printf("\n------------- ft_split -----------\n");
	printf("\ntest %d: Normal \"this is a test\",' '\n",i++);
	ft_print_double_arr(ft_split("this is a test",' '));
	printf("\ntest %d: One Word \"OUSSAMA\",' '\n",i++);
	ft_print_double_arr(ft_split("OUSSAMA",' '));
	printf("\ntest %d: No String\n",i++);
	ft_print_double_arr(ft_split("",' '));
	printf("\ntest %d: No delimeter i give it 0\n",i++);
	ft_print_double_arr(ft_split("this is a test",0));
	printf("\ntest %d: Diffrent delimeter\n",i++);
	ft_print_double_arr(ft_split("this is a test",'\n'));
	printf("\ntest %d: NULL for str\n",i++);
	ft_print_double_arr(ft_split(NULL,' '));
	
	//ft_itoa
	printf("\n------------- ft_itoa -----------\n");
	printf("%s\n",ft_itoa(1234));
	printf("%s\n",ft_itoa(-42));
	printf("%s\n",ft_itoa(2147483647));
	printf("%s\n",ft_itoa(-2147483648));
	printf("%s\n",ft_itoa(214748364));
	printf("%s\n",ft_itoa(1998));

	//ft_strmapi	
	printf("\n------------- ft_strmapi -----------\n");
	//ft_putstr(ft_strmapi("this is a test",ft_test),'\n');

	//ft_striteri	
	printf("\n------------- ft_striteri -----------\n");
	//char str[] = "this is a test\n";
	//ft_striteri(str,ft_test);

	//ft_putchar_fd
	printf("\n------------- ft_putchar_fd -----------\n");
	ft_putchar_fd('A',1);
	ft_putchar_fd('\n',1);

	//ft_putstr_fd
	printf("\n------------- ft_putstr_fd -----------\n");
	ft_putstr_fd("this is a test for ft_putstr_fd\n",1);

	//ft_putendl_fd
	printf("\n------------- ft_putendl_fd -----------\n");
	ft_putendl_fd("this is a test for ft_putendl_fd",1);

	//ft_putnbr_fd
	printf("\n------------- ft_putnbr_fd -----------\n");
	ft_putnbr_fd(-2147483648,1);
	ft_putchar_fd('\n',1);
	ft_putnbr_fd(2147483647,1);
	ft_putchar_fd('\n',1);
	ft_putnbr_fd(0,1);
	ft_putchar_fd('\n',1);
	ft_putnbr_fd(42,1);
	ft_putchar_fd('\n',1);
	ft_putnbr_fd(-42,1);
	ft_putchar_fd('\n',1);
}
