/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 08:09:06 by skrasin           #+#    #+#             */
/*   Updated: 2019/10/29 19:20:50 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFF_SIZE (4096)
#define COUNT_SIZE (1024)

int				ft_error(const char *path)
{
	int			i;

	i = 0;
	write(STDERR_FILENO, "ft_cat: ", 8);
	while (*path)
		write(STDERR_FILENO, path++, 1);
	write(STDERR_FILENO, ": ", 2);
	while (sys_errlist[errno][i] != '\0')
		write(STDERR_FILENO, sys_errlist[errno] + i++, 1);
	write(STDERR_FILENO, "\n", 1);
	return (1);
}

void			ft_read_write(int fd)
{
	char		buf[BUFF_SIZE];
	size_t		count;
	ssize_t		len;

	count = COUNT_SIZE;
	len = 1;
	while (len)
	{
		len = read(fd, buf, count);
		write(STDOUT_FILENO, buf, len);
	}
	write(STDOUT_FILENO, "\n", 1);
}

int				ft_cat(char *path)
{
	ssize_t		fd;
	ssize_t		len;
	char		buf[BUFF_SIZE];

	len = 1;
	fd = open(path, O_RDWR);
	if (fd == -1 && errno != EISDIR)
	{
		fd = open(path, O_RDONLY);
	}
	while (fd > 2 && len != 0)
	{
		len = read(fd, buf, BUFF_SIZE);
		if (len == -1)
			break ;
		write(STDOUT_FILENO, buf, len);
	}
	if (fd > 2)
		close(fd);
	else
		return (ft_error(path));
	return (0);
}

int				main(int argc, char **argv)
{
	int			i;
	int			out;

	i = 1;
	out = 0;
	if (argc == 1)
	{
		ft_read_write(STDIN_FILENO);
	}
	else
	{
		while (i < argc)
		{
			out |= ft_cat(argv[i]);
			i++;
		}
	}
	return (out);
}
