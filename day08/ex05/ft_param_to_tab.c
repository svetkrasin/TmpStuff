/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 06:09:16 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 23:05:36 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>

char	**ft_split_whitespaces(char *str);

int							ft_strlen(char *str)
	int a;

	a = 0;
	while (*str++)
		a++;
	return (a);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char *duplicate;

	duplicate = (char*)malloc((ft_strlen(src) + 1) * sizeof(char));
	duplicate = ft_strcpy(duplicate, src);
	return (duplicate);
}

struct s_stock_par *ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*stock;
	int				i;
	int				j;

	stock = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1));
	if (!stock)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		stock[i].size_param = j;
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		stock[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	stock[i].str = 0;
	return (stock);
}
