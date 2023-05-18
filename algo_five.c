/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:08:52 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/24 16:59:49 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	void	ft_space(t_node **a, t_node **b, int len)
{
	int		i;
	int		min;
	t_node	*trav;

	i = 0;
	trav = *a;
	while (i < len)
	{
		min = ft_min_data(*a, len);
		trav = trav->next;
		if (trav->data == min)
		{
			ft_into_action(a, trav->index);
			ft_push_b(a, b);
			write(1, "pb\n", 3);
			if (len == 4)
				break ;
			i = -1;
			trav = *a;
			len--;
			ft_indexing(*a, len);
		}
		i++;
	}
}

void	ft_algo_of_five(t_node **stack_a, int len)
{
	t_node	*stack_b;
	int		i;

	if (!stack_a || !*stack_a)
		return ;
	stack_b = NULL;
	ft_indexing(*stack_a, len);
	ft_space(stack_a, &stack_b, len);
	ft_algo_of_three(stack_a, 3);
	i = ft_size(stack_b);
	while (i--)
	{
		ft_push_a(stack_a, &stack_b);
		write(1, "pa\n", 3);
	}
}
