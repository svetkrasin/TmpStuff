/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:19:50 by ifavi             #+#    #+#             */
/*   Updated: 2019/07/29 16:26:04 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define MIN(x, y) ((x) > (y) ? (y) : (x)) 
#define MIN3(x, y, z) MIN(MIN(x,y), MIN(y, z))

enum {
	EMPTY = 0,
	OBSTACLE,
	FULL,
	COUNT
};

enum {
	H = 0,
	W,
	D
};

void	print_bsq_result(char base[COUNT], char* map, int dimmension[D], int max)
{
	int		i;
	char	ch;

	i = -1;
	while (++i < dimmension[W] * dimmension[H])
	{
		ch = base[EMPTY];
		if (i / dimmension[W] <= max / dimmension[W] && i / dimmension[W] > max / dimmension[W] - map[max] &&
			i % dimmension[W] <= max % dimmension[W] && i % dimmension[W] > max % dimmension[W] - map[max])
			ch = base[FULL];
		if (map[i] == 0)
			ch = base[OBSTACLE];
		 //ch = '0' + map[i];
		write(1, &ch, 1);
		if (i % dimmension[W] == dimmension[W] - 1)
			write(1, "\n", 1);
	}
}

void	solve_bsq(char base[COUNT], char* map, int dimmension[D])
{
	int		i;
	char	*solution;
	char	score;
	int		max;

	i = -1;
	max = 0;
	solution = malloc(dimmension[H] * dimmension[W]);
	while (++i < dimmension[H] * dimmension[W])
	{
		if (i / dimmension[W] == 0 || i % dimmension[W] == 0)
			score = 1;
		else
			score = 1 + MIN3(solution[i - 1], solution[i - dimmension[W]], solution[i - dimmension[W] - 1]);
		if (map[i] == base[OBSTACLE])
			score = 0;
		if (score > solution[max])
			max = i;
		solution[i] = score;
	}
	print_bsq_result(base, solution, dimmension, max);
	free(solution);
}

int main()
{
	int dimmension[] = { 9, 27 };
	solve_bsq(".ox", "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo", dimmension);
	return (0);
}