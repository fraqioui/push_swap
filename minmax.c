/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:00:03 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/13 08:00:05 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//returning the max data
int	ft_max_data(t_node *trav, int len)
{
	int	max;

	max = trav->next->data;
	trav = trav->next->next;
	while (--len)
	{
		if (max < trav->data)
			max = trav->data;
		trav = trav->next;
	}
	return (max);
}
//returning the min data
int	ft_min_data(t_node *trav, int len)
{
	int	min;

	min = trav->next->data;
	trav = trav->next->next;
	while (--len)
	{
		if (min > trav->data)
			min = trav->data;
		trav = trav->next;
	}
	return (min);
}
//returning the node that has the min data
t_node	*ft_min_node(t_node *last, int len)
{
	int		min;
	t_node	*save;

	if (!last)
		return (NULL);
	min = last->next->data;
	save = last->next;
	last = last->next->next;
	while (--len)
	{
		if (min > last->data)
		{
			min = last->data;
			save = last;
		}
		last = last->next;
	}
	return (save);
}
//returning the node that has the minimum moves
t_node	*ft_min_n_moves(t_node *last, int len)
{
	int		min;
	t_node	*save;

	if (!last)
		return (NULL);
	min = last->next->n_moves;
	save = last->next;
	last = last->next->next;
	while (--len)
	{
		if (min > last->n_moves)
		{
			min = last->n_moves;
			save = last;
		}
		last = last->next;
	}
	return (save);
}
//returning the node that has the max pos_a
t_node	*ft_max_pos_a(t_node *last, int len)
{
	int		max;
	t_node	*save;

	if (!last)
		return (NULL);
	max = last->next->n_moves;
	save = last->next;
	last = last->next->next;
	while (--len)
	{
		if (max < last->pos_a)
		{
			max = last->pos_a;
			save = last;
		}
		last = last->next;
	}
	return (save);
}
