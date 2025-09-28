/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:17:06 by oussama           #+#    #+#             */
/*   Updated: 2025/09/28 00:52:32 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifdef BUFFER_SIZE
#else
	#define	BUFFER_SIZE 1024
#endif

#include <stdlib.h>
#include <unistd.h>

char	*ft_creat_line(int fd, char *kept_str);
char	**ft_split(char const *s, char c);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_final_line(char *kept_str);
size_t  ft_strlen(const char *str);

#endif
