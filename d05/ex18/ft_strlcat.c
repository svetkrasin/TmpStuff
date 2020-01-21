/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:05:17 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/16 20:24:05 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int unsigned i;
	int unsigned j;
	int unsigned result;

	i = 0;
	j = 0;
	result = 0;
	while (dest[i] != '\0')
		i++;
	while (src[result] != '\0')
		result++;
	if (size < i)
		result += size;
	else
		result += i;
	while (src[j] != '\0' && i + 1 < size)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (result);
}
