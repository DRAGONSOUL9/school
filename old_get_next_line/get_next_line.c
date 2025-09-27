/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:55:15 by oussama           #+#    #+#             */
/*   Updated: 2025/09/26 06:37:02 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_final_line(char *str)
{
	char	*line;
	size_t	size;

	if (!str)
		return (NULL);
	size = 0;
	while(str[size] && str[size] != '\n')
		size++;
	if(str[size] == '\n')
		size++;
	line = malloc(size + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line,str,size + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*keeper;
	static size_t	counter;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	char	*line;
	ssize_t	r_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r_bytes = read (fd, buff, BUFFER_SIZE);
	if (r_bytes > 0 || ft_strlen(keeper) > 0)
	{
		while (r_bytes > 0)
		{
			buff[r_bytes] = '\0';
			if (!keeper)
				keeper = ft_strdup(buff);
			else
			{
				tmp = ft_strjoin(keeper, buff);
				free(keeper);
				keeper = tmp;
			}
			if (ft_strchr(buff, '\n'))
				break;
			r_bytes = read (fd, buff, BUFFER_SIZE);
		}
		line = ft_final_line(keeper);
		tmp = ft_cut_line(line, keeper);
		free(keeper);
		keeper = tmp;
	}
	else
		return (NULL);
	//printf("%ld\n",counter);
	counter++;
	return (line);
}

void	ft_print(char *str)
{
	size_t	len = 0;

	while (str[len])
		len++;
	write (1, str,len);
}

int main (int ac, char **av)
{
	int	fd;
	char	*line;
	int	i = 0;
	int	lines = ft_atoi(av[2]);

	if (ac != 3 || lines <= 0)
	{
		write (1, "incorect input\n", 15);
		return (1);
	}
	fd = open (av[1],O_RDONLY);
	//line = get_next_line(fd);
	//ft_print(line);
	while (i < lines)
	{
		line = get_next_line(fd);
		ft_print(line);
		i++;
	}
	close(fd);
	return (0);
}
