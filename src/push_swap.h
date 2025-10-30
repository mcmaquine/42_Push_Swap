/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:24:03 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/30 15:49:13 by mmaquine         ###   ########.fr       */
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
int		check_min_max(long n);
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
void	solve(t_stack *a, t_stack *b, t_stack *com_list);
//Utils
int		*create_int(int n);
#endif

/*
deb http://deb.debian.org/debian/ trixie main contrib non-free
Incluir a lina acima no arquivo /etc/apt/sources.list
fazer apt update

add no /etc/environment 
LD_LIBRARY_PATH="/home/user/.local/share/Steam/steamcmd/linux32:/home/user/.local/share/Steam/steamcmd/linux64:/home/user/cs2ds/game/bin/linuxsteamrt64:/home/user/cs2ds/game/csgo/bin/linuxsteamrt64"
*/