/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:02:49 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/13 08:02:51 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_duplicated(t_node *head, int l_size)
{
	t_node	*com;
	int		check;
	int		i;

	check = 0;
	if (!head)
		return (-1);
	head = head->next;
	while (--l_size)
	{
		i = l_size - 1;
		com = head->next;
		while (i >= 0)
		{
			if (head->data == com->data)
				check++;
			com = com->next;
			i--;
		}
		head = head->next;
	}
	if (check > 0)
		return (-1);
	return (1);
}

int	ft_sorted(t_node *list, int len)
{
	if (!list)
		return (-1);
	list = list->next;
	while (--len)
	{
		if (list->data > list->next->data)
			return (-1);
		list = list->next;
	}
	return (1);
}

int	ft_size(t_node *list)
{
	int		i;
	t_node	*trav;

	i = 0;
	trav = list;
	if (!list)
		return (0);
	while (list->next != trav)
	{
		i++;
		list = list->next;
	}
	i++;
	return (i);
}
