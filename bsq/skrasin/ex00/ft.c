/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifavi <ifavi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 06:43:02 by ifavi             #+#    #+#             */
/*   Updated: 2019/07/31 00:23:06 by ifavi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memcpy(void *dst, void *src, unsigned long size)
{
	unsigned long i;

	i = 0;
	while (i * sizeof(unsigned long long) < size)
	{
		((unsigned long long*)dst)[i] = ((unsigned long long*)src)[i];
		i++;
	}
	i *= sizeof(unsigned long long);
	while (i < size)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_eol(char *str)
{
	unsigned long i;

	i = 0;
	while(str[i] != 0 && str[i] != '\n')
		i++;
	return str + i;
}

void	*ft_memset(void *dest, unsigned char ch, size_t size)
{
	unsigned char	*data;
	unsigned long	i;

	i = 0;
	data = dest;
	while(i < size)
		data[i++] = ch;
	return (dest);
}
