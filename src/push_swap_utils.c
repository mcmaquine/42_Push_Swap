/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:39:58 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/31 19:58:35 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_int(int n)
{
	int	*p;

	p = ft_calloc(1, sizeof(int));
	*p = n;
	return (p);
}

/*
	Return 1 if stack *a is ordenated, 0 otherwise
*/
int	check_ordenation(t_stack *a)
{
	t_list *last;

	last = ft_lstlast(a->data);
	while(last->prev)
	{
		if (*(int *)last->content > *(int *)last->prev->content)
			return (0);
		last = last->prev;
	}
	return (1);
}

/*
	If n exists on stack stk, return its index, otherwise
return -1. Index 0 is the top element.
*/
int	get_index(t_stack *stk, int n)
{
	t_list	*list;
	int		idx;

	list = stk->head;
	idx = 0;
	while (list)
	{
		if (n == *(int *)list->content)
			return (idx);
		idx++;
		list = list->prev;
	}
	return (-1);
}

int	*get_smallest(t_stack *stk)
{
	int		*small;
	t_list	*list;

	list = stk->head;
	small = list->content;
	while(list)
	{
		if (*small < *(int *)list->content)
			small = list->content;
		list = list->prev;
	}
	return (small);
}
