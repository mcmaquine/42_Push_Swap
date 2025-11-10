/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:43:11 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/07 15:44:31 by mmaquine         ###   ########.fr       */
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
	t_list	data;
	t_list	head;
}	t_stack;

int		check_ordenation(t_stack *a);
//stack utils
void	lifo_add(t_stack *l, int n);
int		pop(t_stack *stack);
//validation
int		fill_stack(t_stack *a, int argc, char **argv);
#endif