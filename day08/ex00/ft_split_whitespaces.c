/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 01:02:29 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 11:54:13 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_skip(char *s)
{
	while (*s == 32 || (*s >= 9 && 13 >= *s))
		s++;
	return (s);
}

int		ft_lenth_word(char *s)
{
	int i;

	i = 0;
	while (s[i] > 32 && s[i] < 127)
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
		str = ft_skip(str);
		n = ft_lenth_word(str);
		if (n == 0)
			return (i);
		i++;
		str += n;
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
	vocab = malloc(words * sizeof(char*) + 1);
	i = -1;
	while (++i < words)
	{
		str = ft_skip(str);
		vocab[i] = malloc(ft_lenth_word(str) * sizeof(char) + 1);
		j = -1;
		while (++j < ft_lenth_word(str))
			vocab[i][j] = str[j];
		vocab[i][j] = '\0';
		str += ft_lenth_word(str);
	}
	vocab[i] = 0;
	return (vocab);
}
