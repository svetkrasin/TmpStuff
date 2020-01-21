/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifavi <ifavi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 06:19:26 by ifavi             #+#    #+#             */
/*   Updated: 2019/07/31 00:35:43 by ifavi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>

# define MIN(x, y) ((x) > (y) ? (y) : (x))
# define MAX(x, y) ((x) > (y) ? (x) : (y))

# define MIN3(x, y, z) MIN(MIN(x,y), MIN(y, z))

typedef struct  s_list
{
	int				idx;
	struct s_list	*next;
}				t_list;

typedef union	u_fourcc
{
	unsigned int i4;
	char		 c[4];
}				t_fourcc;

typedef struct	s_ctx
{
	int			fd;
	t_fourcc	base;
	t_list		*head;
	t_list		*curr;
	t_list		*tail;
	int			height;
	int			width;
	int			max_value;
	int			max_idx;
	int			row;
}				t_ctx;

void			*ft_memset(void *dest, unsigned char ch, size_t size);
void			*ft_memcpy(void *dst, void *src, unsigned long size);
char			*ft_eol(char *str);

int				solve_bsq(const char *filename);

#endif
