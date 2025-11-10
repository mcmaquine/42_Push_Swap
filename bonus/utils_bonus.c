/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:39:28 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/07 15:39:46 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	exec(t_stack *a, t_stack com_list)
{
	t_stack	*b;
}
