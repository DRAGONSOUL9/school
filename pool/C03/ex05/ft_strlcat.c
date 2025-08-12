/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:05:59 by oel--mou          #+#    #+#             */
/*   Updated: 2025/07/24 10:27:48 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_size;
	unsigned int	s_size;
	unsigned int	i;
	unsigned int	r;

	d_size = ft_strlen(dest);
	s_size = ft_strlen(src);
	if (size <= d_size)
		return (size + s_size);
	i = 0;
	r = d_size;
	while (i < s_size && r < (size -1))
	{
		dest[r] = src[i];
		r++;
		i++;
	}
	dest[r] = '\0';
	return (d_size + s_size);
}
