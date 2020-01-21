/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:14:16 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 14:14:45 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H

typedef struct		s_perso
{
	char	*name;
	double	life;
	int		age;
	int		profession;
}					t_perso;

#endif
