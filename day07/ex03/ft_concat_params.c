/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:24:28 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/18 19:14:24 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
