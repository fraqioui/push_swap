/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:09:00 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/13 08:09:02 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ft_keep_place(t_node **stack_a, t_node **stack_b, int len)
{
	int		n;
	t_node	*min_moves;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	n = ft_size(*stack_b);
	//after pushing n node to stack b, the updated length of stack a is (len - n).
	len = len - n;
	//finding the best element to push to stack a.
	while (n)
	{
		//calculate the moves each element in stack b needs to be in its right place in stack a.
		ft_moves_calc(*stack_a, *stack_b, len, n);
		//looking for the element that requires the minimum moves.
		min_moves = ft_min_n_moves(*stack_b, n);
		//taking advantage of indexes to reduce the number of moves using rr and rrr actions.
		if (min_moves->pos_a * min_moves->index > 0)
			ft_apply_moves_a_same(stack_a, stack_b, min_moves);
		else if (min_moves->pos_a * min_moves->index <= 0)
			ft_apply_moves_a_diff(stack_a, stack_b, min_moves);
		//after placing the best element to the top of stack b and making its place in stack a. We can push it to stack a.
		ft_push_a(stack_a, stack_b);
		write(1, "pa\n", 3);
		//increase the length of stack a after pushing to it.
		len++;
		//decrease the length of stack b after poping from it.
		n--;
		//index the two stacks again.
		ft_indexing(*stack_a, len);
		ft_indexing(*stack_b, n);
	}
	//and so on until the stack b is empty.
}

void	ft_algo_lis(t_node **stack_a, int len)
{
	t_node	*min_node;
	t_node	*stack_b;

	if (!stack_a || !*stack_a)
		return ;
	//looking for the node that has the min data to start from searching for the largest increasing subsequence.
	min_node = ft_min_node(*stack_a, len);
	stack_b = NULL;
	//find the largest increasing subsequence: LIS
	ft_largest_increasing_subsequence(min_node, len);
	//save the LIS
	ft_save_lis(*stack_a, len);
	//indexing the stack a. (positively in the top middle, and negatively in the bottom middle).
	ft_indexing(*stack_a, len);
	//in ft_apply_moves_b function, I pushed every node that does not belong to the LIS to stack b.
	ft_apply_moves_b(stack_a, &stack_b, len);
	//ft_keep_place finds the best element that needs the minimum moves to push to stack a.
	ft_keep_place(stack_a, &stack_b, len);
	//ft_into_action places any specified node to the top. 
	//Here, it returns the minimum number to the top. So that, the list turns out to be sorted.
	ft_into_action(stack_a, min_node->index);
}
