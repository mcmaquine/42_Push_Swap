/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:34:32 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/05 13:38:54 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort(int *list, int size)
{
	int	j;
	int i;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (list[i] > list[j])
				swap( list + i, list + j);
	}
}

void	apply_rank