/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:29:03 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/04 10:17:18 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Verify if a number already exists in stack stk. Return 1 it is exists, 0
	otherwise.
*/
int	is_in_stack(t_stack *stk, int n)
{
	int	i;

	i = -1;
	while (++i < stk->size)
	{
		if (*(int *)peek(stk, i) == n)
			return (1);
	}
	return (0);
}

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
Return 1 if num is a valide input and adds it to stack, return 0 if not valid
and do not insert on stack.
*/
int	validate_input(t_stack *stk, char *num)
{
	long	n;

	if (!check_alfa(num) || !check_min_max(num))
		return (0);
	n = ft_atoi(num);
	if (is_in_stack(stk, (int)n))
		return (0);
	lifo_add(stk, (int)n);
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
			if(!validate_input(a, split[i]))
				ok = 0;
		ft_free_split(split);
		split = NULL;
		param++;
		if (!ok)
			break ;
	}
	return (ok);
}
