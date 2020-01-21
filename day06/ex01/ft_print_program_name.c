/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:29:12 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/17 18:53:01 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc > 0)
		while (argv[0][i])
			ft_putchar(argv[0][i++]);
	ft_putchar('\n');
	return (0);
}
