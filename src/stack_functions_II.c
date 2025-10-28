/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_II.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:13:58 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/28 17:14:21 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Move all data to top direction, one by one, de top value goes to the base
of the stack.
*/
void	stack_roll_up(t_stack *stk)
{
	void	*last_content;
	t_list	*last;

	last_content = NULL;
	if (!stk)
		return ;
	if (stk->size != 1)
	{
		last = ft_lstlast(stk->data);
		last_content = last->content;
		last->content = last->prev->content;
		last = last->prev;
		while (last->prev)
		{
			last->content = last->prev->content;
			last = last->prev;
		}
		stk->data->content = last_content;
	}
}

void	stack_roll_down(t_stack *stk)
{
	void	*last_content;
	t_list	*last;

	last_content = NULL;
	if (!stk)
		return ;
	if (stk->size != 1)
	{
		last = stk->data;
		last_content = last->content;
		last->content = last->next->content;
		last = last->next;
		while (last->next)
		{
			last->content = last->next->content;
			last = last->next;
		}
		last->content = last_content;
	}
}

/*
Swap top 2 elements
*/
int	stack_swap(t_stack *stk)
{
	void	*temp;
	t_list	*last;

	if (stk->size > 1)
	{
		last = ft_lstlast(stk->data);
		temp = last->content;
		last->content = last->prev->content;
		last->prev->content = temp;
		return (1);
	}
	return (0);
}

/*
Look to a element in a stack without removing it, pos = 0 is the top, and pos 
increases as the position int the stack goes towards to the base.
If n stack.size the 
*/
void	*peek(t_stack *stk, unsigned int pos)
{
	t_list	*lst;

	lst = ft_lstlast(stk->data);
	if (pos >= (unsigned int)stk->size)
		pos = stk->size - 1;
	while (lst && pos)
	{
		lst = lst->prev;
		pos--;
	}
	return (lst->content);
}