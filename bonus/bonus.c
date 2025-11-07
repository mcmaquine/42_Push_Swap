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
		return (0);
	command = get_next_line(0);
	while (*command != 4)
	{
		if (is_valide_command(command))
		{
			lifo_add(comm_list, command);
		}
		else
		{
			free(command);
			free_list(comm_list);
		}
	}
}