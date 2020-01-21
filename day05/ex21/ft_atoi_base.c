/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:56:32 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/16 23:31:03 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check(char c)
{
	if (c < 65 || (c > 90 && c < 97) || c > 122)
		return (0);
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

int		ft_base_int(char *b)
{
	int i;
	int x;
	int y;

	i = 0;
	x = -1;
	y = 0;
	while (b[i] != '\0')
		i++;
	while (++x < i - 1)
		while (++y < i)
			if (b[x] == b[y] || ft_check(b[x]))
				return (0);
	return (i > 1 ? i : 0);
}

int		ft_atoi_base(char *str, char *base)
{
	int answer;
	int sign;

	answer = 0;
	sign = 1;
	while (*str > 0 || *str < 32)
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0' && *str >= *base && *str <= *base + ft_base_int(base))
	{
		answer = answer * 10 + *str - *base;
		str++;
	}
	return (sign * answer);
}
