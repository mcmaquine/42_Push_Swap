/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:29:03 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/03 16:31:33 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Return 1 if the number is between INT_MIN and INT_MAX including
then, 0 otherwise.
*/
int	check_min_max(long n)
{
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
	int	param;

	param = 1;
	while (param < argc)
	{
		
	}
}
