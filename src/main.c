/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:23:27 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/05 15:39:18 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	copy_stack_to_k(t_stack *a, int *k)
{
	int	i;

	i = -1;
	while (++i < a->size)
		k[i] = *(int *)peek(a, i);
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

static void	init(t_stack *a, t_stack *b, t_stack *com_list)
{
	a->size = 0;
	a->data = NULL;
	a->base = NULL;
	a->head = NULL;
	b->size = 0;
	b->data = NULL;
	b->base = NULL;
	b->head = NULL;
	com_list->size = 0;
	com_list->data = NULL;
	com_list->base = NULL;
	com_list->head = NULL;
}

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	t_stack	commands;
	// int		*k;

	init(&a, &b, &commands);
	if (!fill_stack(&a, argc, argv))
	{
		free_stack(&a);
		return 0;
	}
	// k = ft_calloc(a.size, sizeof(int));
	// copy_stack_to_k(&a, k);
	// sort(k, a.size);
	// apply_rank(&a, k);
	// free(k);
	print_stack(&a);
	//solve(&a, &b, &commands);
	print_commands(&commands);
	free_stack(&a);
}
