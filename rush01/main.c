/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:00:30 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/21 23:05:51 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((i < 10 && s1[i] == s2[i]) || s1[i] == '.' || s2[i] == '.')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int		ft_check_box_income(char **argv, int x, int y, char n)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 3)
		while (++j < 3)
			if (argv[x + i][y + j] == n)
				return (1);
	return (0);
}

int		ft_check_sub_income(char **argv)
{
	int n;
	int i;
	int j;

	n = 1;
	i = 2;
	j = -1;
	while (++n < 9)
		while (++i < 9)
		if (!ft_strcmp(argv[n], argv[i]))
			return (0);
	n = 0;
	while (++n < 10)
	{
		j = -1;
		while (++j < 8)
		{
			i = -1;
			while (++i < 9)
				if (argv[n][i] == argv[n][j] && argv[n][i] != '.')
					return (0);
		}
	}
	i = 0;
	while (++i < 10)
	{
		j = -1;
		while (++j < 9)
			if(!(ft_check_box_income(argv, (i - 1) - ((i - 1) % 3) + 1, j - j % 3, n)))
				return (0);
	}
	return (1);
}

int		ft_skip(char **argv, int *x, int *y)
{
	*x = 0;
	while (++*x < 10)
	{
		*y = -1;
		while (++*y < 9)
		{
			if (argv[*x][*y] == '.')
				return (1);
		}
	}
	return (0);
}

int		ft_check_income(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = -1;
	if (argc != 10)
		return (0);
	while (++i < 10)
		while (++j < 9)
			if (argv[i][j] > '9' || (argv[i][j] < '1' && argv[i][j] != '.'))
				return (0);
	i = 0;
	while (++i < 10)
		if (ft_strlen(argv[i]) != 9)
			return (0);
	if (!ft_check_sub_income(&argv[1]))
		return (0);
	return (1);
}

int		ft_check_col(char **argv, int y, char n)
{
	int i;

	i = 1;
	while (i < 10)
		if (argv[i++][y] == n)
			return (1);
	return (0);
}

int		ft_check_row(char **row, int x, char n)
{
	int i;

	i = 0;
	while (i < 10)
		if (row[x][i++] == n)
			return (1);
	return (0);
}

int		ft_check_box(char **argv, int x, int y, char n)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 3)
		while (++j < 3)
			if (argv[x + i][y + j] == n)
				return (1);
	return (0);
}

int		ft_check(char **argv, int x, int y, int n)
{
	return (!ft_check_row(argv, x, n) && !ft_check_col(argv, y, n) &&
!ft_check_box(argv, (x - 1) - ((x - 1) % 3) + 1, y - y % 3, n) && argv[x][y] == '.');
}

void	ft_printf_sudoku(char **argv)
{
	int i;
	int j;

	i = 0;
	while (++i < 10)
	{
		j = -1;
		while (++j < 9)
		{
			write(1, &argv[i][j], 1);
			if (j < 8)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

int		ft_solve(char **argv)
{
	int x;
	int y;
	char n;

	n = '0';
	if (!ft_skip(argv, &x, &y))
	{
		//ft_printf_sudoku(argv);
		return (1);
	}
	while (++n <= '9')
	{
		if (ft_check(argv, x, y, n))
		{
			argv[x][y] = n;
			if (ft_solve(argv))
				return (1);
			argv[x][y] = '.';
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (!ft_check_income(argc, argv) || !ft_solve(argv))
	{
		//ft_printf_sudoku(argv);
		write(1, "Error\n", 6);
		return (0);
	}
	ft_printf_sudoku(argv);
	return (0);
}
