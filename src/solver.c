/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:59:50 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/04 13:22:37 by mmaquine         ###   ########.fr       */
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
	int *n3;

	while(!check_ordenation(a))
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

void	move_up_down(t_stack *stk, int n, t_stack *comlst, int (*f)(t_stack *))
{
	while (*(int*)peek(stk, 0) != n)
		lifo_add(comlst, f(stk));
}

void	solve_hundred(t_stack *a, t_stack *b, t_stack *com_list)
{
	int	*small;
	int	key_nbr;

	key_nbr = *(int *)peek( a, a->size / 4 - 1);
	while (a->size > 3)
	{
		small = get_smallest(a);
		if (get_index(a, *small) > a->size / 2)
			move_up_down(a, *small, com_list, rra);
		else
			move_up_down(a, *small, com_list, ra);
		lifo_add(com_list, pb(a, b));
	}
	solve_for_three(a, com_list);
	while (b->size > 0)
		lifo_add(com_list, pa(a, b));
}

/*
Start point for solving stack ordenation. This function checks stack size and
choose correct option.
*/
void	solve(t_stack *a, t_stack *b, t_stack *com_list)
{
	while (!check_ordenation(a) || b->size > 0)
	{
		if (a->size < 2)
			return ;
		else if (a->size < 3)
			solve_small(a, com_list);
		else if (a->size < 4)
			solve_for_three(a, com_list);
		else if (a->size > 3 && a->size <= 100)
			solve_hundred(a, b, com_list);
		// else if
			// solve_hundred_plus(a, b, com_list);
	}
}
