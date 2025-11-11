/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turck.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:52:40 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/11 09:41:31 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Same has peek but returns a int instead of a pointer. A shorthand version.
*/
static int	pk(t_stack *stk, int pos)
{
	return (*(int *)peek(stk, pos));
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
Calculate least cost moves to move target idx in b to a
*/
int	find_least_moves(t_stack *a, t_stack *b, int idx)
{
	t_cost	ca;
	t_cost	cb;
	int		*tgt_a;

	tgt_a = find_min_max(a, *(int *)peek(b, idx));
	ca = min_cost(a, get_index(a, *tgt_a));
	cb = min_cost(b, idx);
	if (ca.f == cb.f)
	{
		if (ca.cost > cb.cost)
			return (ca.cost);
		else
			return (cb.cost);
	}
	else
		return (ca.cost + cb.cost);
}

void	do_least_move_to_a(t_stack *a, t_stack *b, int tgt_b, t_stack *com_list)
{
	int	tgt_a;
	int	(*fa)(t_stack *);
	int	(*fb)(t_stack *);

	tgt_a = *(int *)find_min_max(a, tgt_b);
	if (a->size / 2 >= get_index(a, tgt_a))
		fa = ra;
	else
		fa = rra;
	if (b->size / 2 >= get_index(b, tgt_b))
		fb = rb;
	else
		fb = rrb;
	while (pk(a, 0) != tgt_a || pk(b, 0) != tgt_b)
	{
		if (pk(a, 0) != tgt_a && pk(b, 0) != tgt_b && fa == ra && fb == rb)
			lifo_add(com_list, rr(a, b));
		else if (pk(a, 0) != tgt_a && pk(b, 0) != tgt_b
			&& fa == rra && fb == rrb)
			lifo_add(com_list, rrr(a, b));
		else if (pk(a, 0) != tgt_a)
			lifo_add(com_list, fa(a));
		else if (pk(b, 0) != tgt_b)
			lifo_add(com_list, fb(b));
	}
}

void	turck(t_stack *a, t_stack *b, t_stack *com_list)
{
	int	least_cost;
	int	new_least;
	int	tgt_b;
	int	i;

	while (a->size > 3)
		lifo_add(com_list, pb(a, b));
	solve_for_three(a, com_list);
	while (b->size > 0)
	{
		tgt_b = 0;
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
		do_least_move_to_a(a, b, *(int *)peek(b, tgt_b), com_list);
		lifo_add(com_list, pa(a, b));
	}
}
