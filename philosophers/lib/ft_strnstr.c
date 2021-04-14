/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:29:53 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 13:29:59 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned int i;
	unsigned int j;

	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[j] != '\0')
	{
		i = 0;
		if (s1[j] == s2[0])
		{
			while (s2[i] != '\0' && s1[i + j] == s2[i] && (i + j) < len)
				i++;
		}
		if (s2[i] == '\0')
			return ((char *)&s1[j]);
		j++;
	}
	return (0);
}
