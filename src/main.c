/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:23:27 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/26 20:02:06 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int	nums[10] = {1, 3, 6, 5, 7, 9, 10, 11, 12, 10};
	int	*arr;
	int	i = 1;
	t_stack	stack;

	stack.data = NULL;
	arr = ft_calloc(10, sizeof(int));
	arr[0] = nums[0];
	push(&stack, arr);
	while (i < 10)
	{
		arr[i] = nums[i];
		push(&stack, (arr + i));
		i++;
	}
	while (stack.size)
	{
		ft_printf("%d ", *(int *)pop(&stack));
	}
}
