/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_swap_II_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:02:04 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/10 13:53:24 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ra(t_stack *a)
{
	if (a->size > 1)
	{
		stack_roll_up(a);
		return (RA);
	}
	return (0);
}

int	rb(t_stack *b)
{
	if (b->size > 1)
	{
		stack_roll_up(b);
		return (RB);
	}
	return (0);
}

int	rr(t_stack *a, t_stack *b)
{
	if ((b->size > 1) && (a->size > 1))
	{
		ra(a);
		rb(b);
		return (RR);
	}
	return (0);
}

int	rra(t_stack *a)
{
	if (a->size > 1)
	{
		stack_roll_down(a);
		return (RRA);
	}
	return (0);
}

int	rrb(t_stack *b)
{
	if (b->size > 1)
	{
		stack_roll_down(b);
		return (RRB);
	}
	return (0);
}
