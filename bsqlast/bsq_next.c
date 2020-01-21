/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifavi <ifavi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 00:19:59 by ifavi             #+#    #+#             */
/*   Updated: 2019/07/31 04:23:19 by ifavi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "ft.h"

#define EMPTY 0
#define OBSTACLE 1
#define FULL 2

#define INVALID(ch, b) (ch != b[EMPTY] && ch != b[OBSTACLE])

int		parse_rules(t_ctx *ctx, int fd)
{
	char	ch;

	ctx->height = 0;
	ctx->base.i4 = 0x30303030;
	ch = -1;
	while (read(fd, &ch, 1) > 0)
	{
		ctx->base.i4 >>= 8;
		if (ch == 0 || ch == '\n')
			return (1);
		if (ctx->base.c[0] < '0' || ctx->base.c[0] > '9')
			return (0);
		ctx->height = ctx->height * 10 + (ctx->base.c[0] - '0');
		ctx->base.c[3] = ch;
	}
	return (0);
}

int		parse_line(t_ctx *ctx)
{
	t_list	*next;
	int		i;
	char	ch;

	i = 0;
	while (read(STDIN_FILENO, &ch, 1) > 0)
		if (ch == '\n' || INVALID(ch, ctx->base.c))
			break ;
		else if (++i && ch == ctx->base.c[OBSTACLE])
		{
			next = malloc(sizeof(t_list));
			next->idx = i + ctx->row * ctx->width;
			next->next = 0;
			if (ctx->curr == 0)
				ctx->curr = next;
			if (ctx->tail)
				ctx->tail->next = next;
			else
				ctx->head = next;
			ctx->tail = next;
		}
	if (ctx->width != 0 && i != ctx->width)
		return (1);
	ctx->width = i;
	return (0);
}

int		*check_line(t_ctx *ctx, int *prev_line)
{
	int		pc_score[2];
	int		i;
	int		*next_line;

	i = 0;
	next_line = malloc(ctx->width * sizeof(*next_line));
	while (i < ctx->width)
	{
		if (prev_line && i > 0)
			pc_score[0] = 1 + MIN3(pc_score[1], prev_line[i], prev_line[i - 1]);
		else
			pc_score[0] = 1;
		if (ctx->curr && (ctx->curr->idx % ctx->width) == i)
		{
			pc_score[0] = 0;
			ctx->curr = ctx->curr->next;
		}
		next_line[i++] = pc_score[0];
		pc_score[1] = pc_score[0];
		if (pc_score[0] > ctx->max_value)
			ctx->max_idx = i - 1 + ctx->row * ctx->width;
		ctx->max_value = MAX(ctx->max_value, pc_score[0]);
	}
	free(prev_line);
	return (next_line);
}

void	print_bsq(t_ctx *ctx)
{
	t_list	*node;
	int		i;

	i = 0;
	node = ctx->head;
	while (i < ctx->width * ctx->height)
	{
		if (node && node->idx == i)
		{
			node = node->next;
			write(1, &ctx->base.c[OBSTACLE], 1);
		}
		else if (i / ctx->width <= ctx->max_idx / ctx->width &&
			i % ctx->width <= ctx->max_idx % ctx->width &&
			i / ctx->width + ctx->max_value > ctx->max_idx / ctx->width &&
			i % ctx->width + ctx->max_value > ctx->max_idx % ctx->width)
			write(1, &ctx->base.c[FULL], 1);
		else
			write(1, &ctx->base.c[EMPTY], 1);
		if (i % ctx->width == ctx->width - 1)
			write(1, "\n", 1);
		i++;
	}
}

int		solve_bsq_stdin(void)
{
	t_ctx	ctx;
	int		*line;

	line = 0;
	ft_memset(&ctx, 0, sizeof(ctx));
	if (parse_rules(&ctx, STDIN_FILENO) == 0)
		return (1);
	while (ctx.row < ctx.height)
	{
		if (parse_line(&ctx))
			return (1);
		line = check_line(&ctx, line);
		if (line == 0)
			return (1);
		ctx.row++;
	}
	if (ctx.width == 0 || ctx.height == 0)
		return (1);
	print_bsq(&ctx);
	return (0);
}
