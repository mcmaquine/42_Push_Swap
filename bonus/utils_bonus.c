/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:39:28 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/10 14:58:38 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void exec_command(int com, t_stack *a, t_stack *b)
{
	if (com == RA)
		ra(a);
	else if (com == RB)
		rb(b);
	else if (com == RR)
		rr(a, b);
	else if (com == RRA)
		rra(a);
	else if (com == RRB)
		rrb(b);
	else if (com == RRR)
		rrr(a, b);
	else if (com == SA)
		sa(a);
	else if (com == SB)
		sb(b);
	else if (com == SS)
		ss(a, b);
	else if (com == PA)
		pa(a, b);
	else if (com == PB)
		pb(a, b);
}

/*
	Return 1 if stack *a is ordenated, 0 otherwise
*/
int	check_ordenation(t_stack *a)
{
	t_list	*last;

	last = ft_lstlast(a->data);
	while (last->prev)
	{
		if (*(int *)last->content > *(int *)last->prev->content)
			return (0);
		last = last->prev;
	}
	return (1);
}

/*
Exec commands on com_list over stack *a and *b.
*/
void	exec(t_stack *a, t_stack *b, t_stack *com_list)
{
	int	command;

	while (com_list->size > 0)
	{
		command = pop(com_list);
		exec_command(command, a, b);
	}
	if (check_ordenation(a) && b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	free_stack(b);
}

int	*create_int(int n)
{
	int	*p;

	p = ft_calloc(1, sizeof(int));
	*p = n;
	return (p);
}
