/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:59:50 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/29 16:48:30 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ordenation(t_stack *a)
{
	t_list *last;

	last = ft_lstlast(a->data);
	while(last->prev)
	{
		if (*(int *)last->content > *(int *)last->prev->content)
			return (0);
		last = last->prev;
	}
	return (1);
}

void	solve_small(t_stack *a, t_stack *com_list)
{
	int	*n1;
	int	*n2;

	while(!check_ordenation(a))
	{
		n1 = peek(a, 0);
		n2 = peek(a, -1);
		if (*n1 > *n2)
			push (com_list, ra(a));
  		n1 = peek(a, 0);
		n2 = peek(a, 1);
		if (*n1 > *n2)
			push (com_list, sa(a));
		n1 = peek(a, 1);
		n2 = peek(a, 2);
			push (com_list, rra(a));
	}
}

void	solve(t_stack *a, t_stack *b, t_stack *com_list)
{
	(void)b;
	if (a->size < 4)
	{
		solve_small(a, com_list);
	}
}