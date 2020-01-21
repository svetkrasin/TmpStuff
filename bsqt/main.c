/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifavi <ifavi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 00:24:27 by ifavi             #+#    #+#             */
/*   Updated: 2019/07/31 01:29:38 by ifavi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == i)
		solve_bsq(STDIN_FILENO);
	while(i < argc)
	{
		if (solve_bsq(argv[i++]))
			write(STDERR_FILENO, "map error\n", 10);
		write(STDOUT_FILENO, "\n", 1);
	}
}
