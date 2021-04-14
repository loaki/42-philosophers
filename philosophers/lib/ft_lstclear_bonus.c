/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:27:32 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/06 16:32:54 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*list;

	list = *lst;
	while (list->next)
	{
		tmp = list->next;
		(*del)(list->content);
		free(list);
		list = tmp;
	}
	if (lst)
	{
		(*del)(list->content);
		free(list);
	}
	*lst = NULL;
}
