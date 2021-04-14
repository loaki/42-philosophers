/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:28:31 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/08 13:43:35 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)src;
	str2 = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	if (str2 > str1)
		while (i < n)
		{
			str2[n - 1] = str1[n - 1];
			n--;
		}
	else
		while (i < n)
		{
			str2[i] = str1[i];
			i++;
		}
	return (dest);
}
