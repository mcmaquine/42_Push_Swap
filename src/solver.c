/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:59:50 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/11 09:38:25 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Solve if stack a has 3 elements.
*/
void	solve_for_three(t_stack *a, t_stack *com_list)
{
	int	*n1;
	int	*n2;
	int	*n3;

	while (!check_ordenation(a))
	{
		n1 = peek(a, 0);
		n2 = peek(a, 1);
		n3 = peek(a, -1);
		if ((*n2 > *n1) && (*n2 > *n3))
			lifo_add(com_list, rra(a));
		n1 = peek(a, 0);
		n2 = peek(a, 1);
		n3 = peek(a, -1);
		if ((*n1 > *n2) && (*n1 > *n3))
			lifo_add(com_list, ra(a));
		n1 = peek(a, 0);
		n2 = peek(a, 1);
		if (*n1 > *n2)
			lifo_add(com_list, sa(a));
	}
}

void	solve_small(t_stack *a, t_stack *com_list)
{
	int	*n1;
	int	*n2;

	while (!check_ordenation(a))
	{
		n1 = peek(a, 0);
		n2 = peek(a, -1);
		if (*n1 > *n2)
			lifo_add(com_list, sa(a));
	}
}

void	rotate_stack(t_stack *stk, int n, t_stack *comlst, int (*f)(t_stack *))
{
	while (*(int *)peek(stk, 0) != n)
		lifo_add(comlst, f(stk));
}

/*
Calculate minimum movements to reach top. Returns a struct which contains min
cost and direction.
*/
t_cost	min_cost(t_stack *stk, int idx)
{
	t_cost	min_cost;

	if (stk->size / 2 >= idx)
	{
		min_cost.cost = idx;
		min_cost.f = ra;
	}
	else
	{
		min_cost.cost = stk->size - idx;
		min_cost.f = rra;
	}
	return (min_cost);
}

/*
Start point for solving stack ordenation. This function checks stack size and
choose correct option.
*/
void	solve(t_stack *a, t_stack *b, t_stack *com_list)
{
	int	*small;

	while (!check_ordenation(a) || b->size > 0)
	{
		if (a->size < 2)
			return ;
		else if (a->size < 3)
			solve_small(a, com_list);
		else if (a->size < 4)
			solve_for_three(a, com_list);
		else if (a->size > 3)
		{
			turck(a, b, com_list);
			small = get_smallest(a);
			if (get_index(a, *small) > a->size / 2)
				rotate_stack(a, *small, com_list, rra);
			else
				rotate_stack(a, *small, com_list, ra);
		}
	}
}
