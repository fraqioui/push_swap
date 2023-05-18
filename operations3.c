/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:13:56 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/24 19:13:57 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rotate_b(t_node **b_head)
{
	if (!b_head || !(*b_head))
		return ;
	*b_head = (*b_head)->next;
}

void	ft_rotate_a_b(t_node **a_head, t_node **b_head)
{
	ft_rotate_a(a_head);
	ft_rotate_b(b_head);
}

void	ft_rev_rotate_a(t_node **a_head)
{
	if (!a_head || !(*a_head))
		return ;
	*a_head = (*a_head)->prev;
}

void	ft_rev_rotate_b(t_node **b_head)
{
	if (!b_head || !(*b_head))
		return ;
	*b_head = (*b_head)->prev;
}

void	ft_rev_rotate_a_b(t_node **a_head, t_node **b_head)
{
	ft_rev_rotate_a(a_head);
	ft_rev_rotate_b(b_head);
}
