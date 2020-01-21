/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 09:41:32 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/18 19:14:08 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *array;
	int i;

	i = 0;
	if (max > min)
		array = (int*)malloc((max - min) * sizeof(int));
	else
		return (0);
	if (!array)
		return (0);
	while (min <= max)
		array[i++] = min++;
	return (array);
}
