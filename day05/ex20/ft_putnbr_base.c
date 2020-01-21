/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:05:55 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/16 23:27:35 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_check(char c)
{
	if (c < 65 || (c > 90 && c < 97) || c > 122))
		return (0);
	if (c < 65 || (c > 90 && c < 97) || c > 122))
		return (0);
	if (c < 48 || c > 57))
		return (0);
	return (1);
}

int		ft_base_int(char *base)
{
	int i;
	int x;
	int y;

	i = 0;
	x = -1;
	y = 0;
	while (base[i] != '\0')
		i++;
	while (++x < i - 1)
		while (++y < i)
			if (base[x] == base[y] || ft_check(base[x])
				return 0;
	return (i > 1 ? i : 0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr_base(147483648, base);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= ft_base_int(base))
	{
		ft_putnbr_base(nbr / ft_base_int(base), base);
		ft_putnbr_base(nbr % ft_base_int(base), base);
	}
	else
	{
		ft_putchar(*base + nbr);
	}
}
