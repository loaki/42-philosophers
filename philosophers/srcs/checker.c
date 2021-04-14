/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:31:28 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/03/31 22:31:28 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_struct	st;
	char		**instr;
	int			i;

	i = -1;
	if (ac == 1)
		return (0);
	init_struct(&st);
	if (!parse_arg(&st, ac, av) || !check_instr(&st) ||
	!(instr = ft_split(st.instr, ' ')))
	{
		write(2, "Error\n", 6);
		return (free_struct(&st));
	}
	while (instr[++i])
		exec_instr(&st, instr[i], 0);
	if (!check_stack(&st))
		printf("KO\n");
	else
		printf("OK\n");
	free(instr);
	free_struct(&st);
	return (0);
}
