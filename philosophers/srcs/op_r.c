/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:22:44 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 17:23:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_r(t_stack *stack)
{
	int i;
	int top;

	i = 0;
	top = stack->tab[0];
	while (i < stack->size - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[stack->size - 1] = top;
}

void		op_r(t_struct *st, char *instr)
{
	if (st->stack_a.size > 1 && (ft_strcmp(instr, "ra") == 0 ||
	ft_strcmp(instr, "rr") == 0))
		apply_r(&st->stack_a);
	if (st->stack_b.size > 1 && (ft_strcmp(instr, "rb") == 0 ||
	ft_strcmp(instr, "rr") == 0))
		apply_r(&st->stack_b);
}
