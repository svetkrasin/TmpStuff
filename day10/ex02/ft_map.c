/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:14:25 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/22 17:37:38 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *arr;
	int i;

	arr = (int*)malloc(length * sizeof(int));
	i = -1;
	while (++i < length)
		arr[i] = f(tab[i]);
	return (arr);
}
