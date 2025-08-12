/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:20:01 by oel--mou          #+#    #+#             */
/*   Updated: 2025/07/24 10:48:47 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	di;
	unsigned int	si;

	di = 0;
	si = 0;
	while (dest[di])
		di++;
	while (src[si] && si < nb)
	{
		dest[di] = src[si];
		di++;
		si++;
	}
	dest[di] = '\0';
	return (dest);
}
