/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:56:17 by oussama           #+#    #+#             */
/*   Updated: 2025/09/26 06:14:00 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifdef BUFFER_SIZE
#else
	#define BUFFER_SIZE 1024
#endif

char    *get_next_line(int fd);
char    *ft_strchr(const char *s, int c);
size_t  ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t  ft_strlcat(char *dst, const char *src, size_t size);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *str);
char    *ft_cut_line(char *line, char *keeper);
int     ft_atoi(const char *str);

#endif
