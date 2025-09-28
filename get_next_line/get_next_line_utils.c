/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:31:44 by oussama           #+#    #+#             */
/*   Updated: 2025/09/28 01:48:06 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	len;

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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;
	size_t	s_len;
	size_t	d_len;

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcat(str, s2, len1 + len2 + 1);
	return (str);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*p;

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

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

char	*ft_final_line(char *kept_str)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	while(kept_str[len] && kept_str[len] != '\n')
		len++;
	if(kept_str[len] == '\n')
		len++;
	line = malloc (len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = kept_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_creat_line(int fd, char *kept_str)
{
	ssize_t	r_bytes;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;

	r_bytes = read(fd, buff, BUFFER_SIZE);
	if (r_bytes < 0)
		return (NULL);
	while(r_bytes > 0)
	{
		buff[r_bytes] = '\0';
		if (!kept_str)
		{
			kept_str = ft_strdup(buff);
			if (!kept_str)
				return (NULL);
		}
		else
		{
			tmp = ft_strjoin(kept_str, buff);
			free(kept_str);
			kept_str = tmp;
		}
		if (!kept_str)
			return (NULL);
		if (ft_strchr(buff, '\n'))
			break;
		r_bytes = read(fd, buff, BUFFER_SIZE);
		if(r_bytes < 0)
		{
			free(kept_str);
			return (NULL);
		}
	}
	return (kept_str);
}
