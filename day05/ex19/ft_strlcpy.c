/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:11:47 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/16 23:22:28 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int len;

	i = -1;
	len = 0;
	while (src[len] != '\0')
		len++;
	while (src[++i] != '\0' && i + 1 < size)
		dest[i] = src[i];
	dest[i] = '\0';
	return (len);
}
