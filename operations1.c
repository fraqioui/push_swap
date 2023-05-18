/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:54:58 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/24 18:42:55 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_swap_a(t_node *a_head)
{
	int	tmp;

	if (a_head == NULL || ft_size(a_head) == 1)
		return ;
	tmp = a_head->next->data;
	a_head->next->data = a_head->next->next->data;
	a_head->next->next->data = tmp;
}

void	ft_swap_b(t_node *b_head)
{
	int	tmp;

	if (b_head == NULL || ft_size(b_head) == 1)
		return ;
	tmp = b_head->next->data;
	b_head->next->data = b_head->next->next->data;
	b_head->next->next->data = tmp;
}

void	ft_swap_a_b(t_node *a_head, t_node *b_head)
{
	ft_swap_a(a_head);
	ft_swap_b(b_head);
}
