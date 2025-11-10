/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:32:58 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/07 16:03:51 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h" 

int	main(int argc, char **argv)
{
	char	*command;
	t_stack	*comm_list;

	if (argc == 1)
		return (EXIT_FAILURE);
	if (!fill_stack(&a, argc, argv))
	{
		free_stack(&a);
		ft_putstr_fd("Error", 2);
		return (EXIT_FAILURE);
	}
	if (!read_from_stdin(comm_list))
	{
		ft_putstr_fd("Error", 2);
		return (EXIT_SUCCESS);
	}
}
