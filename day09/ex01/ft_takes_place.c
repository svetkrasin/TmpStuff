/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:55:34 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/19 11:24:12 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	if (hour > -1 && hour < 10)
		printf(" THE FOLLOWING TAKES PLACE BETWEEN %d.00 A.M. AND %d.00 A.M.",
		hour, hour + 1);
	if (hour > 11 && hour < 23)
		printf(" THE FOLLOWING TAKES PLACE BETWEEN %d.00 P.M. AND %d.00 P.M.",
		hour - 12, hour - 12 + 1);
	if (hour == 24)
		printf(" THE FOLLOWING TAKES PLACE BETWEEN %d.00 A.M. AND %d.00 A.M.",
		0, 1);
	if (hour == 11)
		printf(" THE FOLLOWING TAKES PLACE BETWEEN %d.00 A.M. AND %d.00 P.M.",
		hour, 0);
	if (hour == 23)
		printf(" THE FOLLOWING TAKES PLACE BETWEEN %d.00 P.M. AND %d.00 A.M.",
		hour - 12, 0);
}
