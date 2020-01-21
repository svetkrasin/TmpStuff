/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:51:09 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/17 19:00:22 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++j < argc && argc > 0)
	{
		while (argv[j][i])
			ft_putchar(argv[j][i++]);
		ft_putchar('\n');
		i = 0;
	}
	return (0);
}
