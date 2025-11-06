/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:59:50 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/06 14:15:15 by mmaquine         ###   ########.fr       */
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
	int	is_greater;
	int	*number;
	int	*max_min;
	int	i;

	number = NULL;
	i = -1;
	max_min = get_largest(stk);
	is_greater = 0;
	while (++i < stk->size)
	{
		number = peek(stk, i);
		if (*number > target)
		{	
			is_greater = 1;
			if (*max_min > *number)
				max_min = number;
		}
	}
	if (!is_greater)
		return (get_smallest(stk));
	return (max_min);
}

/*
Calculate minimum movements to reach top. Returns a struct which contains min
cost and direction.
*/
int	min_cost(t_stack *stk, int idx)
{
	int	min_cost;

	if (stk->size / 2 >= idx)
		min_cost = idx;
	else
		min_cost = stk->size - idx;
	return (min_cost);
}

/*
Calculate least cost moves to move target idx in b to a
*/
int	find_least_moves(t_stack *a, t_stack *b, int idx)
{
	int	cost_b;
	int	cost_a;
	int	*tgt_a;

	tgt_a = find_min_max(a, *(int *)peek(b, idx));
	cost_a = min_cost(a, get_index(a, *tgt_a));
	cost_b = min_cost(b, idx);
	return (cost_a + cost_b);
}

void	do_least_move_to_a(t_stack *a, t_stack *b, int idx_b, t_stack com_list)
{
	int	tgt_a;
	int (*fa)(t_stack *);
	int (*fb)(t_stack *);

	tgt_a = *(int *)find_min_max(a, *(int *)peek(b, idx_b));
	if ( a->size / 2 >= get_index(a, tgt_a) )
		fa = ra;
	else
		fa = rra;
	if ( a->size / 2 >= idx_b)
		fb = rb;
	else
		fb = rrb;
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
	tgt_b = 0;
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
				//tgt_b = i;
			}
		}
		//do_least_move_to_a(a, b, tgt_b, com_list);
	}
}
