/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:48:28 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/28 21:35:18 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALEXPR_H
# define EVALEXPR_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct				s_stack_numbr
{
	struct s_stack_numbr	*prev;
	int						data;
}							t_stack_numbr;

typedef struct				s_stack_op
{
	struct s_stack_op		*prev;
	char					data;
}							t_stack_op;

int							ft_priority(char c);
int							ft_d(int a, char c, int b);
void						ft_do_op_work(t_stack_numbr **nbrs,
													t_stack_op **ops);
int							eval_expr(char *str);
void						ft_numbr_push_back(t_stack_numbr **begin_list,
													int data);
void						ft_op_push_back(t_stack_op **begin_list,
													char data);
void						ft_putchar(char c);
void						ft_putnbr(int nb);
int							ft_atoi(char *str);
char						*ft_skip(char *s);
int							ft_word_len(char *s);
int							ft_count_words(char *s);
char						**ft_split_whitespaces(char *str);
int							ft_str_is_numeric(char *str);
int							ft_strlen(char *s);

#endif
