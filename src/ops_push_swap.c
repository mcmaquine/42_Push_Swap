/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:40:16 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/28 17:54:24 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *a)
{
	return (stack_swap(a));
}

int sb(t_stack *b)
{
	return (stack_swap(b));
}

int ss(t_stack *a, t_stack *b)
{
	return (stack_swap(a) || stack_swap(b));
}

int pa(t_stack *a, t_stack *b)
{
	int	content;

	if (b->size < 1)
		return (0);
	else
	{
		content = pop(b);
		push(a, content);
	}
	return (1);
}

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
	return (1);
}