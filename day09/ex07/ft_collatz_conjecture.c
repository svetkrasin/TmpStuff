/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:13:14 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 16:58:05 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base < 2)
		return (0);
	else if (base % 2 == 0)
		return (1 + ft_collatz_conjecture(base / 2));
	else
		return (1 + ft_collatz_conjecture(base * 3 + 1));
}
