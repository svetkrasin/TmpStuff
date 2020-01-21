/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:06:45 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/17 19:00:33 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (argc-- > 1)
	{
		while (argv[argc][i])
			ft_putchar(argv[argc][i++]);
		ft_putchar('\n');
		i = 0;
	}
	return (0);
}
