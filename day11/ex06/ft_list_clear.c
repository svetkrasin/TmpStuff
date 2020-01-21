/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:38:15 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/24 13:38:03 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *tmp;
	t_list *elem;

	elem = *begin_list;
	if (!elem)
		return ;
	while (elem)
	{
		tmp = elem;
		free(elem);
		elem = tmp->next;
	}
	*begin_list = 0;
}
