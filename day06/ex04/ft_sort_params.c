/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:14:30 by skrasin           #+#    #+#             */
/*   Updated: 2019/07/17 20:53:13 by skrasin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap_pointer(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (++i < argc - 1 && argc > 0)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			ft_swap_pointer(&(argv[i]), &(argv[i + 1]));
			i = 0;
		}
	}
	i = 0;
	j = 0;
	while (++j < argc && argc > 0)
	{
		ft_putstr(argv[j]);
		ft_putchar('\n');
	}
	return (0);
}
