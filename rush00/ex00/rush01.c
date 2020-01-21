/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:45:48 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/14 16:33:55 by skrasin          ###   ########.fr       */
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
				ft_putchar('/');
			else if (b == 0 && a == x - 1)
				ft_putchar('\\');
			else if (b == y - 1 && a == 0)
				ft_putchar('\\');
			else if (b == y - 1 && a == x - 1)
				ft_putchar('/');
			else if (b == 0 || b == y - 1)
				ft_putchar('*');
			else if (a == 0 || a == x - 1)
				ft_putchar('*');
			else
				ft_putchar(' ');
		ft_putchar('\n');
	}
}
