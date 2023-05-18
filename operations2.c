/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:12:47 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/24 19:12:47 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_push_a(t_node **a_head, t_node **b_head)
{
	t_node	*sep;
	int		i;

	if (!b_head || !(*b_head))
		return ;
	i = ft_size(*b_head);
	sep = (*b_head)->next;
	(*b_head)->next = (*b_head)->next->next;
	(*b_head)->next->prev = *b_head;
	ft_push(a_head, sep);
	if (i == 1)
		*b_head = NULL;
}

void	ft_push_b(t_node **a_head, t_node **b_head)
{
	t_node	*sep;
	int		i;

	if (!a_head || !(*a_head))
		return ;
	i = ft_size(*a_head);
	sep = (*a_head)->next;
	(*a_head)->next = (*a_head)->next->next;
	(*a_head)->next->prev = *a_head;
	ft_push(b_head, sep);
	if (i == 1)
		*a_head = NULL;
}

void	ft_rotate_a(t_node **a_head)
{
	if (!a_head || !(*a_head))
		return ;
	*a_head = (*a_head)->next;
}
