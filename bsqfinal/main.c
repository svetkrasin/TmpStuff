/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifavi <ifavi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 00:24:27 by ifavi             #+#    #+#             */
/*   Updated: 2019/07/31 23:19:17 by ifavi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int solved;

	i = 1;
	solved = 0;
	if (argc == i)
		solve_bsq(0, 0);
	while(i < argc)
	{
		if (!solve_bsq(argv[i++], solved))
			solved++;
		else
			write(STDERR_FILENO, "map error\n", 10);
	}

}
