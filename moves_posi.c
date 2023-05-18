/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_posi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:01:57 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/24 18:37:35 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	void	ft_moves_1(t_node **stack_a, t_node **stack_b, t_node *node)
{
	int	i;

	i = 0;
	while (i++ < (-1 * node->pos_a))
	{
		ft_rev_rotate_a_b(stack_a, stack_b);
		write(1, "rrr\n", 4);
	}
	i = 0;
	while (i++ < ((-1 * node->index) + node->pos_a))
	{
		ft_rev_rotate_b(stack_b);
		write(1, "rrb\n", 4);
	}
}

static	void	ft_moves_2(t_node **stack_a, t_node **stack_b, t_node *node)
{
	int	i;

	i = 0;
	while (i++ < (-1 * node->index))
	{
		ft_rev_rotate_a_b(stack_a, stack_b);
		write(1, "rrr\n", 4);
	}
	i = 0;
	while (i++ < ((-1 * node->pos_a) + node->index))
	{
		ft_rev_rotate_a(stack_a);
		write(1, "rra\n", 4);
	}
}

static	void	ft_moves_3(t_node **stack_a, t_node **stack_b, t_node *node)
{
	int	i;

	i = 0;
	while (i++ < node->pos_a)
	{
		ft_rotate_a_b(stack_a, stack_b);
		write(1, "rr\n", 3);
	}
	i = 0;
	while (i++ < (node->index - node->pos_a))
	{
		ft_rotate_b(stack_b);
		write(1, "rb\n", 3);
	}
}

static	void	ft_moves_4(t_node **stack_a, t_node **stack_b, t_node *node)
{
	int	i;

	i = 0;
	while (i++ < node->index)
	{
		ft_rotate_a_b(stack_a, stack_b);
		write(1, "rr\n", 3);
	}
	i = 0;
	while (i++ < (node->pos_a - node->index))
	{
		ft_rotate_a(stack_a);
		write(1, "ra\n", 3);
	}
}

void	ft_apply_moves_a_same(t_node **stack_a, t_node **stack_b, t_node *node)
{
	int	i;

	i = 0;
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	if (node->index < 0)
	{
		if (node->index <= node->pos_a)
			ft_moves_1(stack_a, stack_b, node);
		else
			ft_moves_2(stack_a, stack_b, node);
	}
	else if (node->index > 0)
	{
		if (node->index >= node->pos_a)
			ft_moves_3(stack_a, stack_b, node);
		else
			ft_moves_4(stack_a, stack_b, node);
	}
}
