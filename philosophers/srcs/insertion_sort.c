/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:51:55 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/04/08 18:09:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_chunk(t_struct *st, int *cp_stack)
{
	int i;

	i = -1;
	while (++i < st->chunk.size)
	{
		st->chunk.tab[i] =
		cp_stack[(int)(i * st->stack_a.size / st->chunk.size)];
	}
	st->chunk.tab[st->chunk.size] = cp_stack[st->stack_a.size - 1];
	st->chunk.size++;
}

int		check_index(t_struct *st, int nb_move)
{
	if ((st->stack_b.tab[st->stack_b.size - 1 - nb_move] !=
		get_high(st->stack_b) && st->stack_b.tab[st->stack_b.size - 1 -
		nb_move] > st->stack_a.tab[0] && st->stack_b.tab[st->stack_b.size
		- 2 - nb_move] < st->stack_a.tab[0]) ||
		(st->stack_b.tab[st->stack_b.size - 1 - nb_move] !=
		get_high(st->stack_b) && st->stack_b.tab[st->stack_b.size - 1 -
		nb_move] < st->stack_a.tab[0] && st->stack_b.tab[st->stack_b.size
		- 2 - nb_move] > st->stack_a.tab[0]))
		return (1);
	if ((st->stack_b.tab[nb_move] != get_low(st->stack_b) &&
		st->stack_b.tab[nb_move] > st->stack_a.tab[0] &&
		st->stack_b.tab[nb_move + 1] < st->stack_a.tab[0]) ||
		(st->stack_b.tab[nb_move] != get_low(st->stack_b) &&
		st->stack_b.tab[nb_move] < st->stack_a.tab[0] &&
		st->stack_b.tab[nb_move + 1] > st->stack_a.tab[0]))
		return (2);
	return (0);
}

void	insert_index(t_struct *st)
{
	int nb_move;

	nb_move = 0;
	while (st->stack_b.size > 1 && nb_move < st->stack_b.size - 1 &&
		get_high(st->stack_b) > st->stack_a.tab[0] && get_low(st->stack_b)
		< st->stack_a.tab[0])
	{
		if (check_index(st, nb_move) == 1)
		{
			nb_move++;
			while (nb_move--)
				exec_instr(st, "rrb", 1);
			break ;
		}
		if (check_index(st, nb_move) == 2)
		{
			nb_move++;
			while (nb_move--)
				exec_instr(st, "rb", 1);
			break ;
		}
		nb_move++;
	}
}

void	insert_to_b(t_struct *st, int nb_move, char *instr)
{
	while (nb_move--)
		exec_instr(st, instr, 1);
	if (st->stack_b.size > 1 && (get_high(st->stack_b) < st->stack_a.tab[0]
		|| get_low(st->stack_b) > st->stack_a.tab[0]))
		while (get_index(st->stack_b, get_high(st->stack_b)) != 0)
		{
			if (get_index(st->stack_b, get_high(st->stack_b)) <=
				st->stack_b.size / 2)
				exec_instr(st, "rb", 1);
			if (get_index(st->stack_b, get_high(st->stack_b)) >
				st->stack_b.size / 2)
				exec_instr(st, "rrb", 1);
		}
	insert_index(st);
	exec_instr(st, "pb", 1);
}

int		insertion_sort(t_struct *st)
{
	int nb_move;

	st->chunk.size = (int)(0.01 * (double)st->stack_a.size + 6);
	if (!(st->chunk.tab = (int *)malloc(sizeof(int) * (st->chunk.size + 1)))
	|| !get_median(st))
		return (0);
	get_rotate_a(st, nb_move);
	while (get_index(st->stack_b, get_high(st->stack_b)) != 0)
	{
		if (get_index(st->stack_b, get_high(st->stack_b)) <=
			st->stack_b.size / 2)
			exec_instr(st, "rb", 1);
		if (get_index(st->stack_b, get_high(st->stack_b)) >
			st->stack_b.size / 2)
			exec_instr(st, "rrb", 1);
	}
	while (st->stack_b.size != 0)
		exec_instr(st, "pa", 1);
	return (1);
}
