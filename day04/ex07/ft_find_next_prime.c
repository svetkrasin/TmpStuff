/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 22:31:53 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/13 23:34:22 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	i = 5;
	if (nb < 0)
	{
		return (nb);
	}
	if (nb < 2)
		return (nb > 1 ? nb : 0);
	else if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int i;

	i = nb;
	while (i < 2147483647)
	{
		if (ft_is_prime(i))
		{
			break ;
		}
		i++;
	}
	return (i == 2 * nb ? nb : i);
}
