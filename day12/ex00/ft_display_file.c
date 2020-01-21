/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:29:44 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/25 08:39:46 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE (4096)
#define COUNT_SIZE (4096)

void		ft_read_write(int fd)
{
	char	buf[BUFF_SIZE];
	size_t	count;
	ssize_t	len;

	count = COUNT_SIZE;
	len = 1;
	while (len)
	{
		len = read(fd, buf, count);
		write(STDOUT_FILENO, buf, len);
	}
	write(STDOUT_FILENO, "\n", 1);
}

void		ft_display_file(const char *name)
{
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return ;
	ft_read_write(fd);
	close(fd);
}

int			main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(STDOUT_FILENO, "File name missing.\n", 19);
	}
	else if (argc > 2)
	{
		write(STDOUT_FILENO, "Too many arguments.\n", 20);
	}
	else
	{
		ft_display_file(argv[1]);
	}
	return (0);
}
