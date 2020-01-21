/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_fast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifavi <ifavi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:15:48 by ifavi             #+#    #+#             */
/*   Updated: 2019/07/31 23:38:57 by ifavi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "file.h"

#define INVALID(ch, b) (ch != b[EMPTY] && ch != b[OBSTACLE])

t_ctx	parse_rules(int fd)
{
	char	ch;
	t_ctx	ctx;

	ft_memset(&ctx, 0, sizeof(ctx));
	ctx.height = 0;
	ctx.base.i4 = 0x30303030;
	ch = -1;
	while (read(fd, &ch, 1) > 0)
	{
		ctx.base.i4 >>= 8;
		if (ch == 0 || ch == '\n')
			break ;
		if (ctx.base.c[0] < '0' || ctx.base.c[0] > '9')
			break ;
		ctx.height = ctx.height * 10 + (ctx.base.c[0] - '0');
		ctx.base.c[3] = ch;
	}
	return (ctx);
}

int		line_width(t_ctx *ctx)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = ctx->data;
	while (buffer[i] != 0 &&
		buffer[i] != '\n')
		i++;
	if (buffer[i] == 0 && ctx->height == 1)
		return (i);
	if (buffer[i] == '\n')
		return (i);
	return (0);
}

int		read_file(t_ctx *ctx, int fd)
{
	char		*buffer;
	ssize_t		size;

	size = 1;
	while (size > 0)
	{
		buffer = malloc(FILE_CHUNK_SIZE);
		size = read(fd, buffer, FILE_CHUNK_SIZE);
		if (size <= 0)
			break ;
		if (ctx->data == 0 && size > 0)
			ctx->data = buffer;
		ctx->size += size;
	}
	return (ctx->size);
}

ssize_t	check(t_ctx *ctx, int **line, int lw, ssize_t i)
{
	int		score;
	int		prev;

	while (++i < ctx->size)
	{
		if (i % lw == ctx->width)
			ft_swap(&line[0], &line[1]);
		else
		{
			if (INVALID(ctx->data[i], ctx->base.c))
				return (0);
			score = 1;
			if (i / lw > 0 && i % lw > 0)
				score += MIN3(prev, line[0][i % lw], line[0][i % lw - 1]);
			if (ctx->data[i] == ctx->base.c[OBSTACLE])
				score = 0;
			line[1][i % lw] = score;
			prev = score;
			if (score > ctx->max_value)
				ctx->max_idx = i;
			ctx->max_value = MAX(ctx->max_value, score);
		}
	}
	return (i);
}

int		solve_bsq(const char *filename, int solved)
{
	int		fd;
	t_ctx	ctx;
	int		*line[2];
	int		result;

	if (filename)
		fd = open(filename, O_RDONLY);
	else
		fd = 0;
	if (fd < 0)
		return (1);
	ctx = parse_rules(fd);
	read_file(&ctx, fd);
	ctx.width = line_width(&ctx);
	if (ctx.width == 0 || ctx.height == 0)
		return (1);
	line[0] = malloc(sizeof(int) * (ctx.width + 1));
	line[1] = malloc(sizeof(int) * (ctx.width + 1));
	result = check(&ctx, line, ctx.width + 1, -1);
	if (result)
		print(&ctx, solved);
	clean(&ctx, line[0], line[1]);
	return (result == ctx.width);
}
