/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:47:29 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/24 23:16:10 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list *tmp;

	tmp = NULL;
	while (begin_list)
	{
		begin_list->next = tmp;
		tmp = begin_list;
		begin_list = begin_list->next;
	}
}
