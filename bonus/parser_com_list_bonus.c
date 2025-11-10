#include "push_swap_bonus.h"

void	free_stack(t_stack *stk)
{
	while (stk->size)
		pop(stk);
}

int is_valid_command(char *com)
{
	if (ft_strlen(com) > 4)
		return (0);
	if (!ft_strcmp(com, "sa\n"))
		return (SA);
	else if (!ft_strcmp(com, "sb\n"))
		return (SB);
	else if (!ft_strcmp(com, "ss\n"))
		return (SS);
	else if (!ft_strcmp(com, "pa\n"))
		return (PA);
	else if (!ft_strcmp(com, "pb\n"))
		return (PB);
	else if (!ft_strcmp(com, "ra\n"))
		return (RA);
	else if (!ft_strcmp(com, "rb\n"))
		return (RB);
	else if (!ft_strcmp(com, "rr\n"))
		return (RR);
	else if (!ft_strcmp(com, "rra\n"))
		return (RRA);
	else if (!ft_strcmp(com, "rrb\n"))
		return (RRB);
	else if (!ft_strcmp(com, "rrr\n"))
		return (RRR);
	return (0);
}

int	read_from_stdin(t_stack *com_list)
{
	char	*command;
	int		comm;

	command = get_next_line(0);
	while (command)
	{
		comm = is_valid_command(command);
		free(command);
		if (comm)
			lifo_add(com_list, comm);
		else
		{
			free_stack(com_list);
			return (0);
		}
		command = get_next_line(0);
	}
	return (1);
}