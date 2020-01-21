/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:29:05 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 13:50:11 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy_n(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i] != '\0')
	{
		if (src[i] >= 33 || src[i] <= 126)
			dest[i] = src[i];
	}
	dest[i] = '\n';
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	char	*begin;
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (++i < argc)
		n += ft_strlen(argv[i]);
	str = (char*)malloc((n + argc + 1) * sizeof(char));
	begin = str;
	i = 0;
	while (++i < argc)
	{
		ft_strcpy_n(str, argv[i]);
		str += ft_strlen(argv[i]) + 1;
	}
	*(--str) = '\0';
	return (begin);
}

int		ft_strstr(char *str, char *to_find)
{
	int check;
	int i;
	int j;

	check = 0;
	i = -1;
	j = -1;
	while (str[++i] != '\0')
	{
		while (to_find[++j] != '\0' && str[i + j] != '\0')
		{
			if (str[i + j] == to_find[j] || str[i + j] == to_find[j] - 32)
				check++;
		}
		if (check == j && to_find[j] == '\0')
		{
			return (1);
		}
		else
		{
			j = -1;
			check = 0;
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char *s;

	s = ft_concat_params(argc, argv);
	if (ft_strstr(s, "president") || ft_strstr(s, "attack")
	|| ft_strstr(s, "Bauer"))
		write(1, "Alert!!!", 8);
	return (0);
}
