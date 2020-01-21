/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:14:33 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/18 18:46:20 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *array;
	int m;

	i = 0;
	m = min;
	if (max > min)
		array = (int*)malloc((max - min) * sizeof(int));
	else
	{
		*range = 0;
		return (0);
	}
	if (!array)
	{
		*range = 0;
		return (0);
	}
	while (min <= max)
		array[i++] = min++;
	*range = array;
	return (max - m);
}
