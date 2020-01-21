/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 21:14:04 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/25 22:35:06 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int		btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + max(btree_level_count(root->left),
			btree_level_count(root->right)));
}
