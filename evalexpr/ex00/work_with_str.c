/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:17:39 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/28 23:44:27 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evalexpr.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

int		ft_atoi(char *str)
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

char	*ft_skip(char *s)
{
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	return (s);
}

int		ft_word_len(char *s)
{
	int i;

	i = 0;
	if (s[i] == '(' || s[i] == ')')
			return (1);
	while (s[i] > 32 && s[i] < 127)
	{
		if (s[i] == '(' || s[i] == ')')
			break ;
		i++;
	}
	return (i);
}

int		ft_count_words(char *s)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (*s != '\0')
	{
		s = ft_skip(s);
		n = ft_word_len(s);
		if (n == 0)
			return (i);
		i++;
		s += n;
	}
	return (i);
}

char	**ft_split_whitespaces(char *str)
{
	char	**vocab;
	int		words;
	int		i;
	int		j;
	int		len;

	i = 0;
	words = ft_count_words(str);
	vocab = (char**)malloc((words + 1) * sizeof(char*));
	while (i < words)
	{
		str = ft_skip(str);
		len = ft_word_len(str);
		vocab[i] = (char*)malloc(len * sizeof(char) + 1);
		j = -1;
		while (++j < len)
			vocab[i][j] = str[j];
		vocab[i][j] = '\0';
		str += len;
		i++;
	}
	vocab[i] = 0;
	return (vocab);
}

int		ft_str_is_numeric(char *str)
{
	int i;

	i = -1;
	if (str[0] == '-' && (str[1] >= '0' && str[1] <= '9'))
		i++;
	while (str[++i] != '\0')
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
