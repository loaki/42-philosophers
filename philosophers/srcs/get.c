/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:51:14 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/04/08 18:09:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_median(t_struct *st)
{
	int *cp_stack;
	int i;
	int tmp;

	i = -1;
	if (!(cp_stack = (int *)malloc(sizeof(int) * (st->stack_a.size))))
		return (0);
	while (++i < st->stack_a.size)
		cp_stack[i] = st->stack_a.tab[i];
	i = 0;
	while (i < st->stack_a.size - 1)
	{
		if (cp_stack[i] > cp_stack[i + 1])
		{
			tmp = cp_stack[i];
			cp_stack[i] = cp_stack[i + 1];
			cp_stack[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	fill_chunk(st, cp_stack);
	free(cp_stack);
	return (1);
}

int		get_high(t_stack stack)
{
	int i;
	int high;

	i = 0;
	high = stack.tab[0];
	while (i < stack.size)
	{
		if (high < stack.tab[i])
			high = stack.tab[i];
		i++;
	}
	return (high);
}

int		get_low(t_stack stack)
{
	int i;
	int low;

	i = 0;
	low = stack.tab[0];
	while (i < stack.size)
	{
		if (low > stack.tab[i])
			low = stack.tab[i];
		i++;
	}
	return (low);
}

int		get_index(t_stack stack, int nb)
{
	int i;

	i = 0;
	while (i < stack.size)
	{
		if (nb == stack.tab[i])
			return (i);
		i++;
	}
	return (0);
}

void	get_rotate_a(t_struct *st, int nb_move)
{
	int i;

	i = 0;
	while (++i < st->chunk.size)
	{
		nb_move = 0;
		while (st->stack_a.size > 1 && nb_move < st->stack_a.size)
		{
			if (st->stack_a.tab[nb_move] >= st->chunk.tab[i - 1] &&
			st->stack_a.tab[nb_move] < st->chunk.tab[i])
			{
				insert_to_b(st, nb_move, "ra");
				nb_move = 0;
			}
			else if (nb_move > 0 && st->stack_a.tab[st->stack_a.size -
			nb_move] >= st->chunk.tab[i - 1] && st->stack_a.tab[st->stack_a.size
			- nb_move] < st->chunk.tab[i])
			{
				insert_to_b(st, nb_move, "rra");
				nb_move = 0;
			}
			else
				nb_move++;
		}
	}
}
