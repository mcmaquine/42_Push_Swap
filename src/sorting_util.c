/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:34:32 by mmaquine          #+#    #+#             */
/*   Updated: 2025/11/04 17:42:43 by mmaquine         ###   ########.fr       */
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

void	quick_sort(int *list, int idx_start, int idx_end)
{
	int	pivot;
	int	pos_pivot;
	int i;
	int	temp;

	if ((idx_end - idx_start) <= 0)
		return ;
	pos_pivot = (idx_end - idx_start)/2;
	pivot = list[pos_pivot];
	i = idx_start;
	while (i <= idx_end)
	{
		if (list[i] > pivot && (i != pos_pivot))
		{
			temp = list[i];
			list[i] = pivot;
			list[pos_pivot] = temp;
			pos_pivot = i;
		}
		i++;
	}
	quick_sort(list, idx_start, idx_start + (idx_end - idx_start)/2);
 	quick_sort(list, idx_start + (idx_end - idx_start)/2 + 1, idx_end);
	return ;
}
