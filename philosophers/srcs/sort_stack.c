/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:23:16 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 17:46:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_struct *st)
{
	if (st->stack_a.size != 3)
	{
		if (st->stack_a.size == 2 && st->stack_a.tab[0] > st->stack_a.tab[1])
			exec_instr(st, "sa", 1);
		return ;
	}
	if (st->stack_a.tab[0] > st->stack_a.tab[1] && st->stack_a.tab[0] >
	st->stack_a.tab[2])
		exec_instr(st, "ra", 1);
	else if (st->stack_a.tab[1] > st->stack_a.tab[0] && st->stack_a.tab[1] >
	st->stack_a.tab[2])
		exec_instr(st, "rra", 1);
	if (st->stack_a.tab[0] > st->stack_a.tab[1])
		exec_instr(st, "sa", 1);
}

void	small_sort(t_struct *st)
{
	int i;
	int	low;
	int index;

	while (st->stack_a.size > 3 && !(index = 0))
	{
		low = st->stack_a.tab[0];
		i = -1;
		while (++i < st->stack_a.size)
			if (st->stack_a.tab[i] < low)
			{
				low = st->stack_a.tab[i];
				index = i;
			}
		if (index < st->stack_a.size / 2)
			while (index--)
				exec_instr(st, "ra", 1);
		else
			while (index++ < st->stack_a.size)
				exec_instr(st, "rra", 1);
		exec_instr(st, "pb", 1);
	}
	sort_three(st);
	while (st->stack_b.size != 0)
		exec_instr(st, "pa", 1);
}

int		sort_stack(t_struct *st)
{
	if (st->stack_a.size < 10 && !check_sort(st))
		small_sort(st);
	else if (!check_sort(st))
	{
		if (!insertion_sort(st))
			return (0);
	}
	return (1);
}
