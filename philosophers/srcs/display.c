/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:26:25 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/04/08 18:16:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_moy(t_stack stack, int start, int end)
{
	int i;
	int moy;

	i = start;
	moy = 0;
	if (start >= end)
		return (stack.tab[i]);
	while (i < end)
	{
		moy += stack.tab[i];
		i++;
	}
	return (moy / (end - start));
}

void	print_stack(t_struct *st, int size_max, int display_max)
{
	int i;

	i = 0;
	while (i < display_max)
	{
		if (st->opt_c == 1)
		{
			print_ac(st, i, size_max, display_max);
			print_bc(st, i, size_max, display_max);
		}
		else
		{
			print_a(st, i, size_max, display_max);
			print_b(st, i, size_max, display_max);
		}
		i++;
	}
}

void	display(t_struct *st, char *op)
{
	int display_max;
	int size_max;

	if (st->stack_a.size > st->stack_b.size)
		size_max = st->stack_a.size;
	else
		size_max = st->stack_b.size;
	if (size_max > 15)
		display_max = 15;
	else
		display_max = size_max;
	st->instr = op;
	printf("\e[1;1H\e[2J");
	printf("%3s . Stack A   Stack B\n %d\n", op, st->nb_instr);
	print_stack(st, size_max, display_max);
	sleep(1);
}
