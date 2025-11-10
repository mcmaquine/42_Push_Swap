/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_swap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:40:16 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/10 11:37:04 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	sa(t_stack *a)
{
	stack_swap(a);
	return (SA);
}

int	sb(t_stack *b)
{
	stack_swap(b);
	return (SB);
}

int	ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
	return (SS);
}

int	pa(t_stack *a, t_stack *b)
{
	int	content;

	if (b->size < 1)
		return (0);
	else
	{
		content = pop(b);
		push(a, content);
	}
	return (PA);
}

/*
Push element in a into b. Nothing happens if a is empty.
*/
int	pb(t_stack *a, t_stack *b)
{
	int	content;

	if (a->size < 1)
		return (0);
	else
	{
		content = pop(a);
		push(b, content);
	}
	return (PB);
}
