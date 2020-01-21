/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifavi <ifavi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:08:35 by ifavi             #+#    #+#             */
/*   Updated: 2019/07/31 23:31:53 by ifavi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <fcntl.h>
# include <unistd.h>
# define FILE_CHUNK_SIZE 4096

# define EMPTY 0
# define OBSTACLE 1
# define FULL 2

# define MIN(x, y) ((x) > (y) ? (y) : (x))
# define MAX(x, y) ((x) > (y) ? (x) : (y))

# define MIN3(x, y, z) MIN(MIN(x,y), MIN(y, z))

typedef union	u_fourcc
{
	unsigned int	i4;
	char			c[4];
}				t_fourcc;

typedef struct	s_chunk
{
	struct s_chunk	*next;
	void			*data;
	unsigned int	start;
	unsigned int	size;
}				t_chunk;

typedef struct	s_ctx
{
	t_fourcc	base;
	int			height;
	int			width;
	char		*data;
	ssize_t		size;
	int			max_value;
	int			max_idx;
	int			row;

}				t_ctx;

void			*ft_memset(void *dest, unsigned char ch, size_t size);
void			ft_swap(int **a, int **b);
void			clean(t_ctx *ctx, int *line_a, int *line_b);
int				solve_bsq(const char *filename, int solved);
void			print(t_ctx *ctx, int solved);

#endif
