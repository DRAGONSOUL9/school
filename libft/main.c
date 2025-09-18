/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:26:05 by oussama           #+#    #+#             */
/*   Updated: 2025/09/18 20:10:38 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <time.h>

void	test_part_1(void);
void	test_part_2(void);
void	test_partbonus(void);

int	main(void)
{
	clock_t	start,end;
	double	cpu_time_used;

	start = clock();

	//test_part_1();
	//test_part_2();
	test_partbonus();
	
	end = clock();
	cpu_time_used = ((double) (end - start));
	printf("\nTime taken: %f seconds\n", cpu_time_used);
	return (0);
}
