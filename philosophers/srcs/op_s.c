/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:22:56 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 17:24:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_s(t_stack *stack)
{
	int tmp;

	if (1 <= stack->size)
	{
		tmp = stack->tab[0];
		stack->tab[0] = stack->tab[1];
		stack->tab[1] = tmp;
	}
}

void		op_s(t_struct *st, char *instr)
{
	if (st->stack_a.size > 1 && ft_strcmp(instr, "sa") == 0 ||
	ft_strcmp(instr, "ss") == 0)
		apply_s(&st->stack_a);
	if (st->stack_b.size > 1 && ft_strcmp(instr, "sb") == 0 ||
	ft_strcmp(instr, "ss") == 0)
		apply_s(&st->stack_b);
}
