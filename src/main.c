/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:23:27 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/28 17:35:55 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# define N 5

void	fill_stack(t_stack *stk)
{
	int	nums[N] = {1, 3, 6, 11, 89};
	for (int i = 0; i < N; i++)
		push (stk, nums[i]);
}

void	print_stack(t_stack *stk)
{
	int	size;

	size = 0;
	while (size < stk->size)
	{
		ft_printf("%d\n", *(int *)peek(stk, size));
		size++;
	}
}

void 	free_stack(t_stack *stk)
{
	while (stk->size)
		pop(stk);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	(void)argc;
	(void)argv;
	stack.data = NULL;
	stack.size = 0;
	fill_stack(&stack);
	print_stack(&stack);
	free_stack(&stack);
}
