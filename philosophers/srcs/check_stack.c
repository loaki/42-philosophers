/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:35:57 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/03/31 22:35:57 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_instr(t_struct *st, char *op, int key)
{
	st->nb_instr++;
	if (op[0] == 's')
		op_s(st, op);
	if (op[0] == 'p')
		op_p(st, op);
	if (op[0] == 'r' && op[1] != 'r')
		op_r(st, op);
	if (op[0] == 'r' && op[1] == 'r')
		op_rr(st, op);
	if (key == 1)
		printf("%s\n", op);
	if (key == 0 && (st->opt_v == 1 || st->opt_c == 1))
		display(st, op);
}

int		check_stack(t_struct *st)
{
	int i;

	i = 0;
	if (st->stack_b.size != 0)
		return (0);
	while (i < st->stack_a.size - 1)
	{
		if (st->stack_a.tab[i] > st->stack_a.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		check_sort(t_struct *st)
{
	int i;

	i = 0;
	while (i < st->stack_a.size - 1)
	{
		if (st->stack_a.tab[i] > st->stack_a.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		check_rsort(t_struct *st)
{
	int i;

	i = 0;
	while (i < st->stack_b.size - 1)
	{
		if (st->stack_b.tab[i] < st->stack_b.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
