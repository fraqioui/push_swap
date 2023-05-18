/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_neg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:02:19 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/24 17:02:21 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ft_moves_5(t_node **stack_a, t_node **stack_b, t_node *node)
{
	int	i;

	i = 0;
	while (i++ < (-1 * node->index))
	{
		ft_rev_rotate_b(stack_b);
		write(1, "rrb\n", 4);
	}
	i = 0;
	while (i++ < node->pos_a)
	{
		ft_rotate_a(stack_a);
		write(1, "ra\n", 3);
	}
}

static void	ft_moves_6(t_node **stack_a, t_node **stack_b, t_node *node)
{
	int	i;

	i = 0;
	while (i++ < (-1 * node->pos_a))
	{
		ft_rev_rotate_a(stack_a);
		write(1, "rra\n", 4);
	}
	i = 0;
	while (i++ < node->index)
	{
		ft_rotate_b(stack_b);
		write(1, "rb\n", 3);
	}
}

void	ft_apply_moves_a_diff(t_node **stack_a, t_node **stack_b, t_node *node)
{
	int	i;

	i = 0;
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	if (node->index < 0 || node->pos_a > 0)
		ft_moves_5(stack_a, stack_b, node);
	else if (node->pos_a < 0 || node->index > 0)
		ft_moves_6(stack_a, stack_b, node);
	else if (node->pos_a == 0 || node->index == 0)
		return ;
}
