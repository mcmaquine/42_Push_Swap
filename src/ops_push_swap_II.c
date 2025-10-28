/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_swap_II.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:02:04 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/28 18:18:03 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *a)
{
	if (a->size > 1)
	{
		stack_roll_up(a);
		return (1);
	}
	return (0);
}

int	rb(t_stack *b)
{
	if (b->size > 1)
	{
		stack_ro
	}
}