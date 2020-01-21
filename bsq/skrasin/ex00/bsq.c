/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifavi <ifavi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:19:50 by ifavi             #+#    #+#             */
/*   Updated: 2019/07/31 00:30:53 by ifavi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ft.h"
#include "vector.h"

#define EMPTY 0
#define OBSTACLE 1
#define FULL 2

#define H 0
#define W 1

void	print_bsq_result(char base[3], char *map, int dimmension[2], int max)
{
	int		i;
	char	ch;

	i = -1;
	while (++i < dimmension[W] * dimmension[H])
	{
		ch = base[EMPTY];
		if (i / dimmension[W] <= max / dimmension[W] &&
			i % dimmension[W] <= max % dimmension[W] &&
			i / dimmension[W] > max / dimmension[W] - map[max] &&
			i % dimmension[W] > max % dimmension[W] - map[max])
			ch = base[FULL];
		if (map[i] == 0)
			ch = base[OBSTACLE];
		write(1, &ch, 1);
		if (i % dimmension[W] == dimmension[W] - 1)
			write(1, "\n", 1);
	}
}

void	solve_bsq(char base[3], char *map, int dimmension[2])
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
			score = 1 + MIN3(solution[i - 1], solution[i - dimmension[W]],
				solution[i - dimmension[W] - 1]);
		if (map[i] == base[OBSTACLE])
			score = 0;
		if (score > solution[max])
			max = i;
		solution[i] = score;
	}
	print_bsq_result(base, solution, dimmension, max);
	free(solution);
}

char	*read_file_and_close(int fd, int dimmension[2])
{
	int				fd;
	unsigned char	ch;
	t_vec			vector;

	if (filename == 0)
		fd = STDOUT_FILENO;
	else
		fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	vector_create(&vector);
	while (read(fd, &ch, 1) > 0)
			vector_push(&vector, &ch, 1);
	vector_push(&vector, "\0", 1);
	if (fd > 2)
		close(fd);
	return (vector.data);
}

int	parse_rules(int fd, t_fourcc *base)
{
	int		height;
	char	ch;

	height = 0;
	base->i4 = 0x30303030;
	ch = -1;
	while (read(fd, &ch, 1) > 0)
	{
		base->i4 >>= 8;
		if (ch == 0 || ch == '\n')
			return (1);
		if (base->c[0] < '0' || base->c[0] > '9')
			return (0);
		height = height * 10 + (base->c[0] - '0');
		base->c[3] = ch;
	}
	return (0);
}

void	parse_and_solve(const char * filename)
{
	char	base[3];
	int		dimmension;
	char 	*map;
	char	*line;

	map = read_file(fd, base, dimmension);
	line = ft_eol(map);
	ft_memcpy(base, )
	base = ft_eol(map) - 3;
	//ch != base[EMPTY] && ch != base[FULL] && ch != base[OBSTACLE]
	solve_bsq(base, map, dimmension);
	free(map);
}

int		main(int argc, char **argv)
{
	int dimmension[2] = { 9, 27 };

	(void)argc;
	(void)argv;
	solve_bsq(".ox", "...............................o..................................o.............................................o.....................................o............................................o..............o.......o.......o................", dimmension);
	return (0);
}
