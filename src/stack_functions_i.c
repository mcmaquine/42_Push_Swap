/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:30:49 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/26 20:24:23 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	delete(void	*data)
{
	if (data)
		free(data);
}

void	push(t_stack *stack, void *data)
{
	if (!stack || !data)
		return ;
	ft_lstadd_back(&(stack->data), ft_lstnew(data));
	stack->head = ft_lstlast(stack->data);
	stack->size = ft_lstsize(stack->data);
	if (stack->size == 1)
		stack->base = ft_lstlast(stack->data); 
}

void	*pop(t_stack *stack)
{
	t_list	*item;
	void	*content;

	item = NULL;
	if (!stack)
		return (NULL);
	item = ft_lstlast(stack->data);
	if (item)
	{
		content = ft_calloc(1, sizeof(int));
		content = item->content;
	}
	ft_lstdelone(ft_lstlast(stack->data), delete);
	stack->size = ft_lstsize(stack->data);
	stack->head = ft_lstlast(stack->data);
	return (content);
}
