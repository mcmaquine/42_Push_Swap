/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:23:27 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/24 16:56:03 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**list;
	long	n;
	int		i;
	int		check;

	if (argc > 1)
	{
		list = ft_split(argv[1], ' ');
		i = 0;
		check = 0;
		while (list[i])
		{
			if (!check_alfa(list[i]))
				check = 1;
			i++;
		}
		if (check)
		{
			ft_putstr_fd("Erro\n", 2);
			ft_free_split(list);
			return (0);
		}
		check = 0;
		i = 0;
		while (list[i])
		{
			n = ft_atoi(list[i]);
			if (!check_min_max(n))
				check = 1;
			i++;
		}
		if (check)
		{
			ft_putstr_fd("Erro\n", 2);
			ft_free_split(list);
			return (0);
		}
		ft_free_split(list);
	}
}
