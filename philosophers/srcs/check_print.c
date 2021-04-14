/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:45:02 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 18:56:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_print_a(t_struct *st, int i, int size_max, int display_max)
{
	if (i == 0 && (!ft_strcmp(st->instr, "sa") ||
		!ft_strcmp(st->instr, "ra") || !ft_strcmp(st->instr, "rra") ||
		!ft_strcmp(st->instr, "ss") || !ft_strcmp(st->instr, "rr")) || i == 1
		&& (!ft_strcmp(st->instr, "sa") || !ft_strcmp(st->instr, "ss")) || i +
		1 >= (int)((double)st->stack_a.size / ((double)size_max /
		(double)display_max)) && (!ft_strcmp(st->instr, "ra") ||
		!ft_strcmp(st->instr, "rra") || !ft_strcmp(st->instr, "rr")))
		return (1);
	return (0);
}

int		check_print_b(t_struct *st, int i, int size_max, int display_max)
{
	if (i == 0 && (!ft_strcmp(st->instr, "sp") ||
		!ft_strcmp(st->instr, "rb") || !ft_strcmp(st->instr, "rrb") ||
		!ft_strcmp(st->instr, "ss") || !ft_strcmp(st->instr, "rr")) || i == 1
		&& (!ft_strcmp(st->instr, "sb") || !ft_strcmp(st->instr, "ss")) ||
		i + 1 >= (int)((double)st->stack_b.size / ((double)size_max /
		(double)display_max)) && (!ft_strcmp(st->instr, "rb") ||
		!ft_strcmp(st->instr, "rrb") || !ft_strcmp(st->instr, "rr")))
		return (1);
	return (0);
}
