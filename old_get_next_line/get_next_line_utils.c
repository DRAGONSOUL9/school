/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:56:08 by oussama           #+#    #+#             */
/*   Updated: 2025/09/26 06:14:02 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dsize)
{
    size_t  i;
    size_t  len;

    i = 0;
    len = 0;
    while (src[len])
        len++;
    if (dsize == 0)
        return (len);
    while (src[i] && i < (dsize - 1))
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (len);
}

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  i;
    size_t  i2;
    size_t  s_len;
    size_t  d_len;

    s_len = ft_strlen(src);
    d_len = ft_strlen(dst);
    if (size <= d_len)
        return (size + s_len);
    i = 0;
    i2 = d_len;
    while (src[i] && i2 < (size - 1))
        dst[i2++] = src[i++];
    dst[i2] = '\0';
    return (d_len + s_len);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  len1;
    size_t  len2;
    char    *str;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    str = malloc(len1 + len2 + 1);
    if (!str)
        return (NULL);
    ft_strlcpy(str, s1, len1 + 1);
    ft_strlcat(str, s2, len1 + len2 + 1);
    return (str);
}

char    *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] && s[i] != (char)c)
        i++;
    if (s[i] == (char)c)
        return ((char *)&s[i]);
    return (NULL);
}

char    *ft_strdup(const char *s)
{
    int     i;
    int     len;
    char    *p;

    len = ft_strlen(s);
    p = malloc(len + 1);
    if (p == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        p[i] = s[i];
        i++;
    }
    p[i] = '\0';
    return (p);
}
char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *str;
    size_t  s_len;

    s_len = ft_strlen(s);
    if (start >= s_len)
        len = 0;
    else if (len > (s_len - start))
        len = (s_len - start);
    str = malloc(len + 1);
    if (!str)
        return (NULL);
    if (len == 0)
        str[0] = '\0';
    else
        ft_strlcpy(str, &s[start], len + 1);
    return (str);
}

char	*ft_cut_line(char *line, char *keeper)
{
	char	*str;
	size_t	line_len;
	size_t	keeper_len;
	size_t	size;

	line_len = ft_strlen(line);
	keeper_len = ft_strlen(keeper);
	size = keeper_len - line_len;
	str = ft_substr(keeper, line_len, size);
	return (str);
}

int ft_atoi(const char *str)
{
    int     i;
    int     sign;
    long    result;

    i = 0;
    sign = 1;
    if (!str)
        return (0);
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    result = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
