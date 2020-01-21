/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:30:05 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/23 22:53:53 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_ai(char *str)
{
	int answer;
	int sign;

	answer = 0;
	sign = 1;
	while (*str > 0 && *str < 33)
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		answer = answer * 10 + *str - 48;
		str++;
	}
	return (sign * answer);
}

int		ft_d(int a, char c, int b, int *r)
{
	if (c == '*')
		return (a * b);
	else if (c == '+')
		return (a + b);
	else if (c == '-')
		return (a - b);
	if (b != 0)
	{
		if (c == '/')
			return (a / b);
		else if (c == '%')
			return (a % b);
	}
	else if (b == 0 && c == '/')
		write(1, "Stop : division by zero\n", 24);
	else if (b == 0 && c == '%')
		write(1, "Stop : modulo by zero\n", 22);
	*r = 0;
	return (0);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr(147483648);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb += 48;
		write(1, &nb, 1);
	}
}

int		main(int argc, char **argv)
{
	int c;
	int answer;

	c = 1;
	if (argc == 4 && ft_strlen(argv[2]) == 1)
	{
		answer = ft_d(ft_ai(argv[1]), argv[2][0], ft_ai(argv[3]), &c);
		if (c)
			ft_putnbr(answer);
	}
	else
		write(1, "0\n", 2);
	return (0);
}
