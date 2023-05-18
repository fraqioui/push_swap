/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:06:21 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/24 18:39:52 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	int	ft_is_odd(int len)
{
	return (len % 2 == 1);
}

static	void	ft_odd(t_node *list, int len)
{
	int	i;

	i = 0;
	while (i <= len / 2)
	{
		list = list->next;
		list->index = i;
		i++;
	}
	i--;
	while (i >= 1)
	{
		list = list->next;
		list->index = -i;
		i--;
	}
}

static	void	ft_even(t_node *list, int len)
{
	int	i;

	i = 0;
	while (i < len / 2)
	{
		list = list->next;
		list->index = i;
		i++;
	}
	while (i >= 1)
	{
		list = list->next;
		list->index = -i;
		i--;
	}
}

void	ft_indexing(t_node *list, int len)
{
	int	i;

	i = 0;
	if (!list)
		return ;
	if (ft_is_odd(len))
		ft_odd(list, len);
	else
		ft_even(list, len);
}

void	ft_into_action(t_node **list, int index)
{
	int	i;

	i = 0;
	if (!list || !*list)
		return ;
	if (index < 0)
	{
		while (i < -1 * index)
		{
			ft_rev_rotate_a(list);
			write(1, "rra\n", 4);
			i++;
		}
	}
	else
	{
		while (i < index)
		{
			ft_rotate_a(list);
			write(1, "ra\n", 3);
			i++;
		}
	}
}
