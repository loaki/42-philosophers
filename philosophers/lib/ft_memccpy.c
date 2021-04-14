/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:28:01 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/05 16:51:18 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)src;
	str2 = (unsigned char *)dest;
	while (n > 0 && (dest || src))
	{
		if ((unsigned char)str1[i] == (unsigned char)c)
		{
			str2[i] = str1[i];
			return (dest + i + 1);
		}
		str2[i] = str1[i];
		i++;
		n--;
	}
	return (NULL);
}
