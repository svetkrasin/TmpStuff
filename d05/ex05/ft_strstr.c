/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:49:21 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/15 23:03:36 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
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
			if (str[i + j] == to_find[j])
				check++;
		}
		if (check == j && to_find[j] == '\0')
		{
			return (str + i);
		}
		else
		{
			j = -1;
			check = 0;
		}
	}
	return (0);
}
