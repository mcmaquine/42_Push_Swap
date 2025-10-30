/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:59:50 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/30 16:13:47 by mmaquine         ###   ########.fr       */
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

void	solve_small(t_stack *a, t_stack *b, t_stack *com_list)
{
	int	*n1;
	int	*n2;
	int *n3;

	while(!check_ordenation(a) || (b->size > 0))
	{
		n1 = peek(a, 0);
		n2 = peek(a, 1);
		n3 = peek(a, -1);
		if ((*n1 < *n2) && (*n1 < *n3)) 
			lifo_add (com_list, pb(a ,b));
  		n1 = peek(a, 0);
		n2 = peek(a, -1);
		if (*n1 > *n2)
			lifo_add (com_list, ra(a));
		n1 = peek(a, 0);
		n2 = peek(a, 1);
		if (*n1 > *n2)
			lifo_add (com_list, sa(a));
		lifo_add (com_list, pa(a, b));
	}
}

void	solve(t_stack *a, t_stack *b, t_stack *com_list)
{
	(void)b;
	if (a->size < 4)
	{
		solve_small(a, b, com_list);
	}
}