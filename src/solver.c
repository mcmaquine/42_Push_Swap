/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:59:50 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/05 21:05:35 by mmaquine         ###   ########.fr       */
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
		else if (a->size > 3 && a->size <= 10)
			solve_tens(a, b, com_list);
	}
}

/*
find the lesser value in stk that is greater than target. If all
elements in stk is lesser than target, return a pointer to lesser value
in stk
*/
int	*find_min_max(t_stack *stk, int target)
{
	int	*number;
	int	*max_in_stk;
	int	i;
	int	target_is_greater;

	number = NULL;
	i = 0;
	max_in_stk = peek(stk, i);
	target_is_greater = 1;
	while (++i < stk->size)
	{
		number = peek(stk, i);
		if (*number < target)
		{	
			target_is_greater = 0;
			if (*max_in_stk < *number)
				max_in_stk = number;
		}
	}
	if (target_is_greater)
		return (get_smallest(stk));
	else
		return (max_in_stk);
}

/*
Calculate minimun movements to reach top.
*/
int	min_cost(t_stack *stk, int n)
{
	
}

/*
Calculate least cost moves to move target idx in b to a
*/
int	find_least_moves(t_stack *a, t_stack *b, int idx)
{
	int	*tgt_b;
	int	cost_b;
	int	cost_a;
	int	*tgt_a;
	int	i;

	tgt_b = peek(b, idx);
	i = -1;
	while (++i < b->size)
	{
		
	}
}

void	turck(t_stack *a, t_stack *b, t_stack *com_list)
{
	int	least_cost;
	int	new_least;
	int	tgt_b;
	int	i;

	least_cost = 0;
	while (a->size > 3)
		lifo_add(com_list, pb(a, b));
	solve_for_three(a, com_list);
	while (b->size > 0)
	{
		i = 0;
		least_cost = find_least_moves(a, b, i);
		while (++i < b->size)
		{
			new_least = find_least_moves(a, b, i);
			if (new_least < least_cost)
			{
				least_cost = new_least;
				tgt_b = i;
			}
		}
		do_least_move_to_a(a, b, tgt_b, com_list);
	}
}
