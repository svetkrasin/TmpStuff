/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:09:04 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/24 18:22:37 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *last;
	t_list *curr;
	t_list *tmp;

	last = NULL;
	curr = *begin_list;
	tmp = NULL;
	while (curr)
	{
		if ((*cmp)(curr->data, data_ref) == 0)
		{
			if (curr == *begin_list)
				*begin_list = curr->next;
			else
				last->next = curr->next;
			tmp = curr;
			curr = curr->next;
			free(tmp);
		}
		else
		{
			last = curr;
			curr = curr->next;
		}
	}
}
