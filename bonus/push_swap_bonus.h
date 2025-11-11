/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:43:11 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/10 13:44:02 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../libft/libft.h"
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# define SA	100
# define SB	101
# define SS 102
# define PA 103
# define PB 104
# define RA 105
# define RB 106
# define RR 107
# define RRA 108
# define RRB 109
# define RRR 110

typedef struct s_stack
{
	int		size;
	t_list	*data;
	t_list	*head;
	t_list	*base;
}	t_stack;

int		check_ordenation(t_stack *a);
void	exec(t_stack *a, t_stack *b, t_stack *com_list);
//stack utils
void	lifo_add(t_stack *l, int n);
void	push(t_stack *stack, int n);
int		pop(t_stack *stack);
void	*peek(t_stack *stk, int pos);
void	free_stack(t_stack *stk);
int		*create_int(int n);
void	ft_lstdellast(t_list **lst, void (*del)(void *));
void	stack_roll_up(t_stack *stk);
void	stack_roll_down(t_stack *stk);
int		stack_swap(t_stack *stk);
//validation
int		fill_stack(t_stack *a, int argc, char **argv);
int		read_from_stdin(t_stack *com_list);
//Push Swap operation
int		ra(t_stack *a);
int		rb(t_stack *b);
int		rr(t_stack *a, t_stack *b);
int		rra(t_stack *a);
int		rrb(t_stack *b);
int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_stack *a, t_stack *b);
int		pa(t_stack *a, t_stack *b);
int		pb(t_stack *a, t_stack *b);
int		rrr(t_stack *a, t_stack *b);
#endif