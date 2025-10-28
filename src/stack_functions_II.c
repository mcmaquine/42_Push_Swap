/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_II.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:13:58 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/28 14:43:23 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
