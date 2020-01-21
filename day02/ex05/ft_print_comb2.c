/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:41:42 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/11 22:23:44 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < 100)
	{
		while (b < 100)
		{
			if (b % 10 >= a % 10 && b / 10 >= a / 10)
			{
				ft_putchar(a / 10 + 48);
				ft_putchar(a % 10 + 48);
				ft_putchar(' ');
				ft_putchar(b / 10 + 48);
				ft_putchar(b % 10 + 48);
				ft_putchar(',');
				ft_putchar(' ');
			}
			b++;
		}
		a++;
	}
}
