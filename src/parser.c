/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:29:03 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/03 21:02:14 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Return 1 if the number is between INT_MIN and INT_MAX including
then, 0 otherwise.
*/
int	check_min_max(char *num)
{
	long	n;

	n = ft_atoi(num);
	if (n >= INT_MIN && n <= INT_MAX)
		return (1);
	else
		return (0);	
}

/*
Return 1 if the *num is numeric only, 0 otherwise
*/
int	check_alfa(char *num)
{
	if (!num)
		return (0);
	while (*num)
	{
		if (ft_isalpha(*num))
			return (0);
		num++;
	}
	return (1);
}

/*
Fill stack, if everything is ok return 1, otherwise return 0
*/
int	fill_stack(t_stack *a, int argc, char **argv)
{
	int		i;
	int		ok;
	int		param;
	char	**split;

	param = 1;
	ok = 0;
	split = NULL;
	while (param < argc)
	{
		ok = 1;
		i = -1;
		split = ft_split(argv[param], ' ');
		while (split[++i])
		{
			if (check_min_max(split[i]) && check_alfa(split[i]))
				lifo_add(a, (int)ft_atoi(split[i]));
			else
				ok = 0;
		}
		ft_free_split(split);
		split = NULL;
		param++;
		if (!ok)
			break ;
	}
	return (ok);
}
