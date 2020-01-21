/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:09:15 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 16:15:51 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIGHT_H
# define FT_FIGHT_H
# define PUNCH "punch"
# define KICK "kick"
# define HEADBUTT "headbutt"
# include "ft_perso.h"

void	ft_fight(t_perso *attacker, t_perso *defense, char *attack);

#endif
