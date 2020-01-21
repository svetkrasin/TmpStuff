/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 21:10:08 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/25 22:20:19 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
												int (*cmpf)(void *, void *))
{
	if (root)
	{
		if (cmpf(root->item, data_ref) > 0)
			btree_search_item(root->right, data_ref, cmpf);
		else if (cmpf(root->item, data_ref) < 0)
			btree_search_item(root->left, data_ref, cmpf);
	}
	return (root);
}
