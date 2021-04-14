/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:56:47 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/04/08 18:58:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_atoi(const char *str, int *overflow)
{
	long long	nb;
	int			i;
	int			s;

	s = 1;
	nb = 0;
	i = 0;
	while ((str[i] == 32) || (str[i] == 12) || (str[i] == 10) ||
			(str[i] == 13) || (str[i] == 9) || (str[i] == 11))
	{
		i++;
	}
	if (str[i] == 45)
		s = s * -1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + str[i] - 48;
		if (nb * s > 2147483647 || nb * s < -2147483648)
			*overflow = 1;
		i++;
	}
	return (nb * s);
}
