/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:23:03 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 17:59:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_arg(t_struct *st, int ac, char **av)
{
	int i;
	int j;

	i = 1;
	if (st->opt_v == 1 || st->opt_c == 1)
		i = 2;
	while (i < ac)
	{
		j = 0;
		while (j++ < i)
			if (j != i && ft_strcmp(av[i], av[j]) == 0)
				return (0);
		j = 0;
		while (av[i][j])
		{
			if ((j == 0 && (av[i][0] == '-' || av[i][0] == '+')) ||
			ft_isdigit(av[i][j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int		parse_arg(t_struct *st, int ac, char **av)
{
	int i;
	int overflow;

	i = 2;
	if (!ft_strcmp(av[1], "-v"))
		st->opt_v = 1;
	else if (!ft_strcmp(av[1], "-c"))
		st->opt_c = 1;
	else
		i = 1;
	overflow = 0;
	st->stack_a.size = ac - i;
	if (!check_arg(st, ac, av) || !(st->stack_a.tab = (int*)malloc(sizeof(int) *
		st->stack_a.size)) || !(st->stack_b.tab = (int*)malloc(sizeof(int) *
		st->stack_a.size)))
		return (0);
	while (i < ac)
	{
		st->stack_a.tab[i - 1 - st->opt_v - st->opt_c] =
		ft_atoi(av[i], &overflow);
		if (overflow != 0)
			return (0);
		i++;
	}
	return (1);
}
