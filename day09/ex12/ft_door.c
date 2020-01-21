/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:16:42 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 15:13:27 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_door.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	close_door(t_door *door)
{
	ft_putstr("Door closing...");
	door->state = CLOSE;
}

void	open_door(t_door *door)
{
	ft_putstr("Door closing...");
	door->state = OPEN;
}

ft_bool	is_door_open(t_door door)
{
	ft_putstr("Door is open?");
	return (door.state == OPEN);
}

ft_bool	is_door_close(t_door door)
{
	ft_putstr("Door is close ?");
	return (door.state == CLOSE);
}
