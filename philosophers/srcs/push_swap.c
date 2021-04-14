/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:23:10 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 17:40:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_struct	st;

	if (ac == 1)
		return (0);
	init_struct(&st);
	if (!parse_arg(&st, ac, av) || !sort_stack(&st))
	{
		write(2, "Error\n", 6);
		return (free_struct(&st));
	}
	return (free_struct(&st));
}
