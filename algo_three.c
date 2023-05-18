/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:08:44 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/24 18:32:33 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	void	ft_helper_1(t_node **a, int max, int min)
{
	if (max == (*a)->data)
	{
		ft_swap_a(*a);
		write(1, "sa\n", 3);
	}
	else if (min == (*a)->data)
	{
		if (max == (*a)->next->data)
		{
			ft_swap_a(*a);
			write(1, "sa\n", 3);
			ft_rev_rotate_a(a);
			write(1, "rra\n", 4);
		}
		else
		{
			ft_rev_rotate_a(a);
			write(1, "rra\n", 4);
		}
	}
	else
		return ;
}

static	void	ft_helper_2(t_node **a, int max, int min)
{
	if (min == (*a)->next->data && max == (*a)->prev->data)
	{
		ft_swap_a(*a);
		write(1, "sa\n", 3);
		ft_rotate_a(a);
		write(1, "ra\n", 3);
	}
	else if (min == (*a)->prev->data && max == (*a)->next->data)
	{
		ft_rotate_a(a);
		write(1, "ra\n", 3);
	}
}

void	ft_algo_of_three(t_node **stack_a, int len)
{
	int	max;
	int	min;

	if (!stack_a || !*stack_a)
		return ;
	max = ft_max_data(*stack_a, len);
	min = ft_min_data(*stack_a, len);
	if (ft_sorted(*stack_a, len) == 1)
		return ;
	if (len == 3)
	{
		ft_helper_1(stack_a, max, min);
		ft_helper_2(stack_a, max, min);
	}
	else
	{
		ft_swap_a(*stack_a);
		write(1, "sa\n", 3);
	}
}
