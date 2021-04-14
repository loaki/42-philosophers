/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:21:55 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 17:22:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_p(t_stack *dest, t_stack *source)
{
	int i;
	int push;

	i = 0;
	if (source->size == 0)
		return ;
	push = source->tab[0];
	source->size--;
	dest->size++;
	while (i < source->size || i < dest->size)
	{
		if (i < dest->size - 1)
			dest->tab[dest->size - i - 1] = dest->tab[dest->size - i - 2];
		if (i < source->size)
			source->tab[i] = source->tab[i + 1];
		i++;
	}
	dest->tab[0] = push;
}

void		op_p(t_struct *st, char *instr)
{
	if (ft_strcmp(instr, "pa") == 0)
		apply_p(&st->stack_a, &st->stack_b);
	if (ft_strcmp(instr, "pb") == 0)
		apply_p(&st->stack_b, &st->stack_a);
}
