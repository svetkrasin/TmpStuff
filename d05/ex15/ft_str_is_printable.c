/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:36:27 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/16 14:30:09 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] < 32 || str[i] > 126)
			return (0);
	return (1);
}
