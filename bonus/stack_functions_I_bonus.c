/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_bonus_I.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:30:49 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/10 10:58:53 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
	Free a pointer.
*/
static void	delete(void	*data)
{
	if (data)
		free(data);
}

/*
Add element at the begining of a queue to be remeved like FIFO.
*/
void	push(t_stack *stack, int n)
{
	int	*num;

	num = create_int(n);
	if (!stack)
		return ;
	ft_lstadd_back(&(stack->data), ft_lstnew(num));
	stack->head = ft_lstlast(stack->data);
	stack->size = ft_lstsize(stack->data);
	stack->base = stack->data;
	if (stack->size == 1)
		stack->base = ft_lstlast(stack->data);
}

int	pop(t_stack *stack)
{
	t_list	*item;
	int		content;

	item = NULL;
	content = 0;
	if (!stack)
		return (0);
	item = ft_lstlast(stack->data);
	if (item)
		content = *(int *)(item->content);
	ft_lstdellast(&(stack->data), delete);
	stack->size = ft_lstsize(stack->data);
	stack->head = ft_lstlast(stack->data);
	return (content);
}

/*
Deletes last element from 
*/
void	ft_lstdellast(t_list **lst, void (*del)(void *))
{
	t_list	*last;
	t_list	*iter;

	iter = *lst;
	last = ft_lstlast(*lst);
	if (last != *lst)
	{
		while (iter->next != last)
			iter = iter->next;
		iter->next = NULL;
		ft_lstdelone(last, del);
	}
	else
	{
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}

/*
Add a element to the end of a list, to be poped as a queue (LAST IN LAST OUT).
*/
void	lifo_add(t_stack *l, int n)
{
	int	*num;

	num = create_int(n);
	if (!l)
		return ;
	ft_lstadd_front(&(l->data), ft_lstnew(num));
	l->head = ft_lstlast(l->data);
	l->size = ft_lstsize(l->data);
	l->base = l->data;
}
