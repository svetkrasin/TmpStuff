/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_steck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:21:34 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/28 22:10:00 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evalexpr.h"

void	ft_numbr_push_back(t_stack_numbr **begin_list, int data)
{
	t_stack_numbr *elem;

	elem = (t_stack_numbr*)malloc(sizeof(t_stack_numbr));
	elem->data = data;
	elem->prev = *begin_list;
	*begin_list = elem;
}

void	ft_op_push_back(t_stack_op **begin_list, char data)
{
	t_stack_op *elem;

	elem = (t_stack_op*)malloc(sizeof(t_stack_op));
	elem->data = data;
	elem->prev = *begin_list;
	*begin_list = elem;
}
