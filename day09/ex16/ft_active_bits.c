/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:15:44 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 16:59:54 by skrasin          ###   ########.fr       */
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

unsigned int	ft_active_bits(int value)
{
	unsigned int n;

	n = 0;
	while (value > 0)
	{
		if ((value & 1) == 1)
			n++;
		value >>= 1;
	}
	return (n);
}
