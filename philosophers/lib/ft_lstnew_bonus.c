/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:27:07 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/06 16:34:05 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(new))))
		return (NULL);
	if (!(new->content = (void *)malloc(sizeof(content))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
