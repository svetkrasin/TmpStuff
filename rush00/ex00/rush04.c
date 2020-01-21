/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:45:57 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/14 16:31:33 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	rush(int x, int y)
{
	int a;
	int b;

	b = -1;
	while (++b < y)
	{
		a = -1;
		while (++a < x)
			if (b == 0 && a == 0)
				ft_putchar('A');
			else if (b == 0 && a == x - 1)
				ft_putchar('C');
			else if (b == y - 1 && a == 0)
				ft_putchar('C');
			else if (b == y - 1 && a == x - 1)
				ft_putchar('A');
			else if (b == 0 || b == y - 1)
				ft_putchar('B');
			else if (a == 0 || a == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
		ft_putchar('\n');
	}
}
