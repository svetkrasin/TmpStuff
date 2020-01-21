/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:43:53 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/25 17:38:20 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*head;
	t_list	*elem;
	t_list	tmp;
	int		check;

	head = *begin_list;
	check = 1;
	while (check)
	{
		check = 0;
		elem = head;
		while (elem != 0 && elem->next != 0)
		{
			if ((*cmp)(elem->data, (elem->next)->data) < 0)
			{
				tmp.data = elem->data;
				elem->data = (elem->next)->data;
				(elem->next)->data = tmp.data;
				check = 1;
			}
		}
	}
}
