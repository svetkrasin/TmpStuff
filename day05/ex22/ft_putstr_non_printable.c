/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 22:32:22 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/16 23:18:12 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putstr_non_printable(char *str)
{
	int i;
	char *s;

	i = -1;
	s = "0123456789abcdef";
	while(str[++i] != '\0')
	{
		if (str[i] <= 31)
		{
			ft_putstr_non_printable(str[i] / s[i]);
			ft_putstr_non_printable(str[i] % s[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
	}
}
