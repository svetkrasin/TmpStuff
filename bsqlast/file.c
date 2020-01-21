/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifavi <ifavi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:15:48 by ifavi             #+#    #+#             */
/*   Updated: 2019/07/31 23:40:44 by ifavi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "file.h"

void	*ft_memset(void *dest, unsigned char ch, size_t size)
{
	unsigned char	*data;
	unsigned long	i;

	i = 0;
	data = dest;
	while (i < size)
		data[i++] = ch;
	return (dest);
}

void	clean(t_ctx *ctx, int *line_a, int *line_b)
{
	char *p;

	p = ctx->data;
	while (p < ctx->data + ctx->size)
	{
		free(p);
		p += FILE_CHUNK_SIZE;
	}
	free(line_a);
	free(line_b);
}

void	ft_swap(int **a, int **b)
{
	int *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	print(t_ctx *ctx, int solved)
{
	ssize_t i;
	ssize_t lw;

	lw = ctx->width + 1;
	i = -1;
	if (solved)
		write(1, "\n", 1);
	while (++i < ctx->size)
	{
		if (i % lw == ctx->width)
			write(1, "\n", 1);
		else if (ctx->data[i] == ctx->base.c[OBSTACLE])
			write(1, &ctx->base.c[OBSTACLE], 1);
		else if (i / lw <= ctx->max_idx / lw &&
			i % lw <= ctx->max_idx % lw &&
			i / lw + ctx->max_value > ctx->max_idx / lw &&
			i % lw + ctx->max_value > ctx->max_idx % lw)
			write(1, &ctx->base.c[FULL], 1);
		else
			write(1, &ctx->base.c[EMPTY], 1);
	}
	write(1, "\n", 1);
}
