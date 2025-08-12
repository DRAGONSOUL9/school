/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:37:23 by oel--mou          #+#    #+#             */
/*   Updated: 2025/07/24 10:44:02 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	di;
	unsigned int	si;

	di = 0;
	si = 0;
	while (dest[di])
		di++;
	while (src[si])
	{
		dest[di] = src[si];
		di++;
		si++;
	}
	dest[di] = '\0';
	return (dest);
}
