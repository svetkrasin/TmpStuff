/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:48:23 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/21 22:53:40 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match(char *s1, char *s2)
{
	if (*s1 == '\0' && s2 == '\0')
		return (1);
	else if (*s1 == '\0' && *s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);
		else if (*(s2 + 1) == '*')
			return (match(s1, s2 + 2));
	}
	else if (*s2 == '*')
		return (match(s1 + 1, s2) || match(s1, s2 + 1));
	else if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	return (0);
}