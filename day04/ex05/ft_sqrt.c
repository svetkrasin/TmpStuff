/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:55:27 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/13 23:16:06 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int subtract;
	int i;
	int compare;

	compare = 1;
	i = 0;
	subtract = 1;
	while (compare < nb && i <= 46341)
	{
		subtract += 2;
		compare += subtract;
		i++;
	}
	if (compare == nb)
	{
		return (++i);
	}
	return (0);
}
