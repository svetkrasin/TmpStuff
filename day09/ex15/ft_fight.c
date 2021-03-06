/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:09:17 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 16:15:58 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fight.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_fight(t_perso *attacker, t_perso *defense, char *attack)
{
	float	strength;

	if (attacker->life <= 0 || defense->life <= 0)
		return ;
	if (attack[0] == 'k')
		strength = 15;
	else if (attack[0] == 'h')
		strength = 5;
	else
		strength = 20;
	defense->life -= strength;
	ft_putstr(attacker->name);
	ft_putstr(" does a judo ");
	ft_putstr(attack);
	ft_putstr(" on ");
	ft_putstr(defense->name);
	ft_putstr("\n");
	if (defense->life <= 0)
	{
		ft_putstr(defense->name);
		ft_putstr(" is dead.\n");
	}
}
