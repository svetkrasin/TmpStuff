/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:57:37 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 15:12:16 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_pointer(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_compact(char **tab, int length)
{
	int i;
	int check;

	i = -1;
	check = 1;
	while (++i < length - 1)
	{
		if (!**tab)
		{
			ft_swap_pointer(&(tab[i]), &(tab[i + 1]));
			i = 0;
			if (i + 1 == length)
				length--;
		}
	}
	return (length);
}
