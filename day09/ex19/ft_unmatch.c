/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:43:14 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 16:47:16 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int i;
	int n;
	int find;

	n = 0;
	while (n < length)
	{
		i = -1;
		find = 0;
		while (++i < length && !find)
			if (i != n)
				find = (tab[i] == tab[n]) ? 1 : 0;
		if (!find)
			return (tab[n]);
		n += 1;
	}
	return (tab[n]);
}
