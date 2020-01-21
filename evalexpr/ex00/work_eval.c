/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_eval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:41:52 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/28 22:27:29 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evalexpr.h"

int		ft_priority(char c)
{
	if (c == '+' || c == '-')
		return (1);
	if (c == '*' || c == '/' || c == '%')
		return (2);
	if (c == ')')
		return (3);
	return (0);
}

int		ft_d(int a, char c, int b)
{
	if (c == '*')
		return (a * b);
	else if (c == '+')
		return (a + b);
	else if (c == '-')
		return (a - b);
	if (b != 0)
	{
		if (c == '/')
			return (a / b);
		else if (c == '%')
			return (a % b);
	}
	return (0);
}

void	ft_do_op_work(t_stack_numbr **nbrs, t_stack_op **ops)
{
	t_stack_numbr	*tmpnb;
	t_stack_op		*tmpop;

	while ((*ops))
	{
		if ((*ops)->data == '(')
		{
			tmpop = (*ops);
			(*ops) = (*ops)->prev;
			free(tmpop);
			break ;
		}
		(*nbrs)->prev->data = ft_d((*nbrs)->data,
				(*ops)->data, (*nbrs)->prev->data);
		tmpop = (*ops);
		tmpnb = (*nbrs);
		(*ops) = (*ops)->prev;
		(*nbrs) = (*nbrs)->prev;
		free(tmpop);
		free(tmpnb);
	}
}

int		eval_expr(char *str)
{
	char				**expression;
	int					i;
	t_stack_op			*ops;
	t_stack_numbr		*nbrs;

	ops = 0;
	nbrs = 0;
	expression = ft_split_whitespaces(str);
	i = -1;
	while (expression[++i])
	{
		if (ft_strlen(expression[i]) == 1 && !ft_str_is_numeric(expression[i]))
		{
			while (ops && ft_priority(ops->data) >=
					ft_priority(expression[i][0]))
				ft_do_op_work(&nbrs, &ops);
			ft_op_push_back(&ops, expression[i][0]);
		}
		else
		{
			ft_numbr_push_back(&nbrs, ft_atoi(expression[i]));
		}
	}
	while (ops)
		ft_do_op_work(&nbrs, &ops);
	return (nbrs->data);
}
