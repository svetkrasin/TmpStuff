/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 09:38:57 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/13 23:20:36 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int fact;

	fact = 1;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 1 || nb >= 13)
	{
		return (0);
	}
	while (nb > 1)
	{
		fact *= nb--;
	}
	return (fact);
}
