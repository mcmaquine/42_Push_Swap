/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:24:03 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/05 13:42:35 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# include "../libft/libft.h"
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
	void	*head;
	void	*base;
	int		size;
	t_list	*data;
}	t_stack;

//Data parser
int		fill_stack(t_stack *a, int argc, char **argv);
int		check_min_max(char *num);
int		check_alfa(char *num);
//Stack funtions
void	push(t_stack *stack, int n);
int		pop(t_stack *stack);
void	ft_lstdellast(t_list **lst, void (*del)(void *));
void	stack_roll_up(t_stack *stk);
void	stack_roll_down(t_stack *stk);
int		stack_swap(t_stack *stk);
void	*peek(t_stack *stk, int pos);
int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_stack *a, t_stack *b);
int		pa(t_stack *a, t_stack *b);
int		pb(t_stack *a, t_stack *b);
int		ra(t_stack *a);
int		rb(t_stack *b);
int		rr(t_stack *a, t_stack *b);
int		rra(t_stack *a);
int		rrb(t_stack *b);
// Lifo functions
void	lifo_add(t_stack *l, int n);
//Solver functions
void	solve(t_stack *a, t_stack *b, t_stack *com_list, int *k);
//Utils
int		*create_int(int n);
int		check_ordenation(t_stack *a);
int		get_index(t_stack *stk, int n);
int		*get_smallest(t_stack *stk);
int		*get_largest(t_stack *stk);
void	rotate_stack(t_stack *stk, int n, t_stack *comlst, int (*f)(t_stack *));
//Sorting algorith for reference
void	sort(int *list, int size);
#endif
