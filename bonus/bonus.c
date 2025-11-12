/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:32:58 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/12 14:02:58 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h" 

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
	t_stack	a;
	t_stack	b;
	t_stack	comm_list;

	if (argc == 1)
		return (EXIT_FAILURE);
	init (&a, &b, &comm_list);
	if (!fill_stack(&a, argc, argv))
	{
		free_stack(&a);
		ft_putstr_fd("Error\n", 2);
		return (EXIT_FAILURE);
	}
	if (a.size == 0)
		return (EXIT_SUCCESS);
	if (!read_from_stdin(&comm_list))
	{
		ft_putstr_fd("Error\n", 2);
		return (EXIT_SUCCESS);
	}
	exec(&a, &b, &comm_list);
	return (EXIT_SUCCESS);
}
