/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:58:17 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 13:11:50 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ultimator.h"
#include <stdlib.h>

void	ft_destroy(char ***factory)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (factory[++i])
	{
		while (**factory[i][++j])
			free(factory[i][j]);
		free(factory[i]);
	}
	free(factory);
}
