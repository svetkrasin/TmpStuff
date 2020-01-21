/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 21:03:00 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/25 22:12:42 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
												int (*cmpf)(void *, void *))
{
	t_btree *node;

	node = *root;
	if (node)
	{
		if ((*cmpf)(node->item, item) > 0)
			btree_insert_data(&(node->right), item, cmpf);
		else
			btree_insert_data((&node->left), item, cmpf);
	}
	node = item;
}
