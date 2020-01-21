/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:16:39 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 17:00:49 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H
# include <unistd.h>

# define OPEN 1
# define CLOSE 0
# define EXIT_SUCCESS 0

typedef int		ft_bool;

struct	s_door {
	int state;
};

typedef struct s_door	t_door;
#endif
