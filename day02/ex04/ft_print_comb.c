/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:52:21 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/11 22:22:57 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_comb(void)
{
	int	a[3];

	a[0] = 0;
	while (a[0] <= 7)
	{
		a[1] = a[0] + 1;
		while (a[1] <= 8)
		{
			a[2] = a[1] + 1;
			while (a[2] <= 9)
			{
				ft_putchar(a[0] + 48);
				ft_putchar(a[1] + 48);
				ft_putchar(a[2] + 48);
				if (a[0] != 7 && a[1] != 8 && a[2] != 9)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				a[2]++;
			}
			a[1]++;
		}
		a[0]++;
	}
}
