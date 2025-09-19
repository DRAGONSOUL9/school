/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpart1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:38:04 by oussama           #+#    #+#             */
/*   Updated: 2025/09/01 00:07:25 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

void test_part_1(void)
{
    char buf[50] = "Hello World";
    char dst[50];
    char *dup;
    void *p;

    printf("\n===== ft_strlen =====\n");
    printf("normal: %zu\n", ft_strlen("Hello"));
    printf("empty: %zu\n", ft_strlen(""));

    printf("\n===== is* / to* =====\n");
    printf("ft_isalpha('A')=%d ft_isdigit('5')=%d ft_isalnum('9')=%d\n",
           ft_isalpha('A'), ft_isdigit('5'), ft_isalnum('9'));
    printf("ft_isascii(128)=%d ft_isascii(127)=%d\n",
           ft_isascii(128), ft_isascii(127));
    printf("ft_isprint(31)=%d ft_isprint(32)=%d\n",
           ft_isprint(31), ft_isprint(32));
    printf("ft_tolower('A')=%c ft_toupper('z')=%c\n",
           ft_tolower('A'), ft_toupper('z'));

    printf("\n===== ft_atoi =====\n");
    printf("\"  -42abc\" → %d\n", ft_atoi("  -42abc"));
    printf("\"2147483647\" (INT_MAX) → %d\n", ft_atoi("2147483647"));
    printf("\"-2147483648\" (INT_MIN) → %d\n", ft_atoi("-2147483648"));
    printf("\"999999999999\" (overflow) → %d\n", ft_atoi("999999999999"));
    printf("\"   +---+42\" (weird signs) → %d\n", ft_atoi("   +---+42"));

    printf("\n===== ft_strncmp =====\n");
    printf("2 chars: %d\n", ft_strncmp("abc","abd",2));
    printf("3 chars: %d\n", ft_strncmp("abc","abd",3));
    printf("empty vs \"a\": %d\n", ft_strncmp("", "a", 1));

    printf("\n===== ft_memcmp =====\n");
    printf("first 2: %d\n", ft_memcmp("abc","abd",2));
    printf("first 3: %d\n", ft_memcmp("abc","abd",3));

    printf("\n===== ft_memset =====\n");
    ft_memset(buf, '*', 5);
    printf("result: %.*s...\n", 10, buf);

    printf("\n===== ft_bzero =====\n");
    ft_bzero(buf, 5);
    printf("first char=%d second char=%d\n", buf[0], buf[1]);

    printf("\n===== ft_memcpy =====\n");
    ft_memcpy(dst, "copy this", 10);
    printf("%s\n", dst);
    // memcpy undefined if overlap: not tested

    printf("\n===== ft_memmove =====\n");
    char overlap[] = "123456789";
    ft_memmove(overlap+2, overlap, 5);
    printf("overlap test: %s\n", overlap);

    printf("\n===== ft_memchr =====\n");
    printf("find 'o': %s\n", (char *)ft_memchr("Hello", 'o', 5));
    printf("not found: %p\n", ft_memchr("Hello", 'x', 5));

    printf("\n===== ft_calloc =====\n");
    p = ft_calloc(5, sizeof(int));
    if (p) {
        printf("calloc ok\n");
        free(p);
    }
    p = ft_calloc(0, 0);
    printf("calloc(0,0) returned %p\n", p);
    free(p);
    // Overflow check
    p = ft_calloc(SIZE_MAX, 2);
    printf("calloc(SIZE_MAX,2) → %p\n", p);

    printf("\n===== ft_strchr / ft_strrchr =====\n");
    printf("strchr: %s\n", ft_strchr("banana", 'a'));
    printf("strrchr: %s\n", ft_strrchr("banana", 'a'));
    printf("not found: %p\n", ft_strchr("banana", 'x'));
    printf("find '\\0': %s\n", ft_strchr("banana", '\0'));

    printf("\n===== ft_strnstr =====\n");
    printf("find World: %s\n", ft_strnstr("Hello World", "World", 11));
    printf("not found: %p\n", ft_strnstr("Hello World", "42", 11));
    printf("empty little: %s\n", ft_strnstr("Hello", "", 5));

    printf("\n===== ft_strdup =====\n");
    dup = ft_strdup("duplicate me");
    printf("dup: %s\n", dup);
    free(dup);
    dup = ft_strdup("");
    printf("dup empty: \"%s\"\n", dup);
    free(dup);

    printf("\n===== ft_strlcpy =====\n");
    ft_strlcpy(dst, "copy safely", sizeof(dst));
    printf("%s\n", dst);
    printf("return val len: %zu\n", ft_strlcpy(dst, "longlonglong", 5));

    printf("\n===== ft_strlcat =====\n");
    ft_strlcpy(dst, "Hello ", sizeof(dst));
    printf("return=%zu result=%s\n", ft_strlcat(dst, "World", sizeof(dst)), dst);
    ft_strlcpy(dst, "Hello", 6);
    printf("size too small return=%zu\n", ft_strlcat(dst, "World", 6));

    printf("\n===== ft_substr =====\n");
    char *test = ft_substr("this is a test",5,2);
    printf("%s and the len is %ld\n",test,ft_strlen(test));
	
    printf("\n===== ft_strjoin =====\n");
    printf("%s\n",ft_strjoin("my name is oussama and i love eating potatos","and this is my second string im trying to join with the first string"));

    printf("\n===== ft_strtrim =====\n");
    char *res = ft_strtrim("         this is a test      ", " ");
    if (res == NULL)
    	printf("Returned NULL (as expected)\n");
    else
	printf("%s\n", res);
    printf("%s\n",ft_strtrim(" "," "));

}
