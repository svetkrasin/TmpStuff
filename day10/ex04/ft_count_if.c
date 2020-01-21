/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:09:10 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/23 02:40:48 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int i;

	i = 0;
	while (*tab)
	{
		if (f(*tab) == 1)
			i++;
		tab++;
	}
	return (i);
}
