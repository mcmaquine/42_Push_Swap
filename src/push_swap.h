/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:24:03 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/26 17:02:42 by mmaquine         ###   ########.fr       */
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
void	push(t_stack *stack, void *data);
void	*pop(t_stack *stack);
#endif
