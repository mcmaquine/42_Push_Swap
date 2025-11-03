/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:23:27 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/31 12:58:37 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# define N 3

void	fill_stack(t_stack *stk)
{
	int	nums[N] = {1,3,2};
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

void	print_commands(t_stack *com_list)
{
	int	com;

	while (com_list->size)
	{
		com = pop(com_list);
		if (com == RA)
			ft_printf("ra\n");
		else if (com == RB)
			ft_printf("rb\n");
		else if (com == RR)
			ft_printf("rr\n");
		else if (com == RRA)
			ft_printf("rra\n");
		else if (com == RRB)
			ft_printf("rrb\n");
		else if (com == RRR)
			ft_printf("rrr\n");
		else if (com == SA)
			ft_printf("sa\n");
		else if (com == SB)
			ft_printf("sb\n");
		else if (com == SS)
			ft_printf("ss\n");
		else if (com == PA)
			ft_printf("pa\n");
		else if (com == PB)
			ft_printf("pb\n");
	}
}

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	t_stack	commands;

	(void)argc;
	(void)argv;
	a.data = NULL;
	b.data = NULL;
	commands.data = NULL;
	a.size = 0;
	b.size = 0;
	commands.size = 0;
	fill_stack(&a);
	print_stack(&a);
	solve(&a, &b, &commands);
	ft_printf("Supostamente ordenado\n");
	print_stack(&a);
	print_commands(&commands);
	free_stack(&a);
}
