/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:41:49 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/03 15:26:13 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
