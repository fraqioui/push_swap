/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:55:20 by fraqioui          #+#    #+#             */
/*   Updated: 2022/11/23 07:55:22 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//largest increasing subsequence: LIS
//I relied on the competitive programming idea of finding the length of the LIS to develop this function. You can find out about this concept in project resources.
void	ft_largest_increasing_subsequence(t_node *min, int n)
{
	t_node	*rstrt;
	t_node	*find;
	int		i;
	int		j;

	i = 1;
	find = min->next;
	while (i < n)
	{
		j = 0;
		rstrt = min;
		while (j < i)
		{
			if (find->data > rstrt->data && find->pos_a < (rstrt->pos_a) + 1)
			{
				find->pos_a = (rstrt->pos_a) + 1;
				find->link = rstrt;
			}
			rstrt = rstrt->next;
			j++;
		}
		find = find->next;
		i++;
	}
}
//saving the LIS
void	ft_save_lis(t_node *last, int n)
{
	t_node	*max;
	int		i;

	max = ft_max_pos_a(last, n);
	i = max->pos_a;
	while (i--)
	{	
		max->n_moves = 1;
		max = max->link;
	}
}
