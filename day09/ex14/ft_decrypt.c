/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:16:41 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 16:06:35 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_perso.h"
#include <stdlib.h>

int		ft_lenth_word(char *s)
{
	int i;

	i = 0;
	while (!(str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122) || !(str[i] < 48 || str[i] > 57))
		i++;
	return (i);
}

int		ft_all_words(char *str)
{
	int i;
	int n;

	i = 0;
	while (str)
	{
		n = ft_lenth_word(str);
		if (n == 0)
			return (i);
		i++;
		str += n + 1;
	}
	return (i);
}

char	**ft_split_whitespaces(char *str)
{
	int		words;
	char	**vocab;
	int		i;
	int		j;

	words = ft_all_words(str);
	vocab = (char **)malloc(words * sizeof(char*) + 1);
	i = -1;
	while (++i < words)
	{
		str = ft_skip(str);
		vocab[i] = (char*)malloc(ft_lenth_word(str) * sizeof(char) + 1);
		j = -1;
		while (++j < ft_lenth_word(str))
			vocab[i][j] = str[j];
		vocab[i][j] = '\0';
		str += ft_lenth_word(str);
	}
	vocab[i] = 0;
	return (vocab);
}

int	ft_atoi(char *str)
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

t_perso		**ft_decrypt(char *str)
{
	char	**age_nom;
	t_perso **persons
	int n;
	int i;
	int j;

	persons = ft_split_whitespaces(str);
	i = -1;
	j = -1;
	while (age_nom)
		n++;
	if (!(persons = (t_perso**)malloc(n / 2 * sizeof(t_perso*))))
		return (0);
	while (++i < n / 2)
		persons[i] -> age = ft_atoi(age_nom[i]);
		while (agenom[++j])
			persons[i] -> name[j] = age_nom[j];
		persons[i] -> name[j] = '\0';
	return (persons);
}
