/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:59:12 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/13 23:16:02 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power < 0 || nb == 0)
	{
		return (0);
	}
	if (power == 0 || nb == 1)
	{
		return (1);
	}
	if (power >= 31 && nb % 2 == 0)
	{
		return (-1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}
