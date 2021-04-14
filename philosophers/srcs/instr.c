/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:19:01 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 17:21:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	unsigned int i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	instr_cmp(char *line)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") ||
	!ft_strcmp(line, "ss") || !ft_strcmp(line, "pa") || !ft_strcmp(line, "pb")
	|| !ft_strcmp(line, "ra") || !ft_strcmp(line, "rb") ||
	!ft_strcmp(line, "rr") || !ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb")
	|| !ft_strcmp(line, "rrr"))
		return (1);
	return (0);
}

static int	check_if_valid_instr(t_struct *st, char buf[], int *index)
{
	int instr_nb;

	buf[*index] = '\0';
	if (buf[0] == 0)
		return (1);
	if (!instr_cmp(buf))
		return (0);
	if (!(st->instr = ft_strjoin(ft_strjoin(st->instr, " "), buf)))
		return (0);
	*index = 0;
	return (1);
}

int			check_instr(t_struct *st)
{
	char	buf[5];
	int		ret;
	int		index;

	index = 0;
	ft_bzero(buf, 5);
	while ((ret = read(0, buf + index, 1)) > 0)
	{
		if (buf[index] == '\n' || index > 3)
		{
			if (index == 0)
				return (1);
			if (!check_if_valid_instr(st, buf, &index))
				return (0);
			ft_bzero(buf, 5);
		}
		else
			index++;
	}
	return (check_if_valid_instr(st, buf, &index));
}
