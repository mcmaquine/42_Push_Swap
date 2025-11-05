/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:59:50 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/05 10:35:09 by mmaquine         ###   ########.fr       */
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

void	rotate_stack(t_stack *stk, int n, t_stack *comlst, int (*f)(t_stack *))
{
	while (*(int*)peek(stk, 0) != n)
		lifo_add(comlst, f(stk));
}

void	solve_tens(t_stack *a, t_stack *b, t_stack *com_list)
{
	int	*small;

	while (a->size > 3)
	{
		small = get_smallest(a);
		if (get_index(a, *small) > a->size / 2)
			rotate_stack(a, *small, com_list, rra);
		else
			rotate_stack(a, *small, com_list, ra);
		lifo_add(com_list, pb(a, b));
	}
	solve_for_three(a, com_list);
	while (b->size > 0)
		lifo_add(com_list, pa(a, b));
}

void	push_chunks_to_b(t_stack *a, t_stack *b, t_stack *com_list, int *k)
{
	int	step;
	int	key_nbr;
	int	index;
	int	*small;

	if (a->size > 100)
		step = a->size / 8;
	else
		step = a->size / 4;
	index = 0;
	while (a->size > 0)
	{
		index += step;
		key_nbr = k[index - 1];
		small = get_smallest(a);
		while (small && (*small <= key_nbr))
		{
			if (get_index(a, *small) > a->size / 2)
				rotate_stack(a, *small, com_list, rra);
			else
				rotate_stack(a, *small, com_list, ra);
			lifo_add(com_list, pb(a, b));
			small = get_smallest(a);
		}
	}
}

void	push_chunks_to_a(t_stack *a, t_stack *b, t_stack *com_list)
{
	int	*big;

	while (b->size > 0)
	{
		big = get_largest(b);
		if (get_index(b, *big) > b->size / 2)
			rotate_stack(b, *big, com_list, rrb);
		else
			rotate_stack(b, *big, com_list, rb);
		lifo_add(com_list, pa(a, b));
	}
}

/*
Start point for solving stack ordenation. This function checks stack size and
choose correct option.
*/
void	solve(t_stack *a, t_stack *b, t_stack *com_list, int *k)
{
	while (!check_ordenation(a) || b->size > 0)
	{
		if (a->size < 2)
			return ;
		else if (a->size < 3)
			solve_small(a, com_list);
		else if (a->size < 4)
			solve_for_three(a, com_list);
		else if (a->size > 3 && a->size <= 10)
			solve_tens(a, b, com_list);
		else if (a->size > 10)
		{
			push_chunks_to_b(a, b, com_list, k);
			push_chunks_to_a(a, b, com_list);
		}
	}
}
