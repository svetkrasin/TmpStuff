/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:59:38 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/18 23:43:08 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_skip(char *s)
{
	while (*s == 32 || (*s >= 9 && 13 >= *s))
		s++;
	return (s);
}

int		ft_word_len(char *s)
{
	int i;

	i = 0;
	while (s[i] > 32 && s[i] < 127)
		i++;
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
		{
			vocab[i][j] = str[j];
		}
		vocab[i][j] = '\0';
		str += len;
		i++;
	}
	vocab[i] = 0;
	return (vocab);
}
