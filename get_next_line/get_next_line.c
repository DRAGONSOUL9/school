/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:21:09 by oussama           #+#    #+#             */
/*   Updated: 2025/09/28 02:54:34 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static size_t	counter;
	static char	*kept_str;
	char		*tmp;
	char		*line;
	size_t		line_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	kept_str = ft_creat_line(fd, kept_str);
	if (!kept_str)
		return (NULL);
	line = ft_final_line(kept_str);
	if (!line)
		return (NULL);
	line_len = ft_strlen(line);
	tmp = ft_substr(kept_str, line_len, ft_strlen(kept_str) - line_len);
	if(!tmp)
	{
		free(line);
		free(kept_str);
		return (NULL);
	}
	free(kept_str);
	kept_str = tmp;
	if(!kept_str[0])
	{
		free(kept_str);
		kept_str = NULL;
	}
	counter++;
	//printf("\n-------------------%ld-------------------\n",counter);
	return (line);
}

int	main(int ac, char **av)
{
	int	fd;
	int	line = 0;
	char	*str;

	if (ac != 2)
		{
		printf("wrong input\n");
		return (1);
	}
	fd = open(av[1],O_RDONLY);
	if (fd == -1)
	{
		printf("thre is no file with that name\n");
		return (1);
	}
	//while(line < atoi(av[2]))
	while((str = get_next_line(fd)))
	{
		if (!str)
			printf("the line returned NULL\n");
		else
			printf("%s",str);
		free(str);
		line++;
	}
	return (0);
}
