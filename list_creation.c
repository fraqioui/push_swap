/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:14:00 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/24 18:36:00 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//create lists' nodes. 
t_node	*ft_new_node(int value)
{
	t_node	*head;

	head = malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->prev = head;
	head->data = value;
	head->index = 1;
	head->pos_a = 1;
	head->link = NULL;
	head->n_moves = 0;
	head->next = head;
	return (head);
}
//after creating the node, I added it to the front of the list.
void	ft_push(t_node **top, t_node *to_add)
{
	if (!to_add)
		return ;
	//if the list is empty, the to_add will be the first node of the list.
	else if (!*top)
	{
		*top = to_add;
		(*top)->next = *top;
		(*top)->prev = *top;
	}
	else
	{
		(*top)->next->prev = to_add;
		to_add->next = (*top)->next;
		to_add->prev = *top;
		(*top)->next = to_add;
	}
}
//list creation
void	ft_list_crea(int ac, char **av, t_node **head)
{
	int		len;
	char	**splitted;
	t_node	*current;
	//splitting each argument on its own.
	while (--ac > 0)
	{
		len = ft_words(av[ac], ' ');
		splitted = ft_split(av[ac], ' ');
		//if an argument is empty display error.
		if (!splitted || !*splitted)
			ft_error();
		//filling out each node with a number (knowing that I've started filling it from the last argument until the first one).
		while (--len >= 0)
		{
			current = ft_new_node(ft_atoi(splitted[len]));
			//protected any allocation failure
			if (!current)
				ft_error();
			//pushing to the front of the list
			ft_push(head, current);
		}
		//freeing before allocating again to avoid memory leaks.
		splitted = ft_alloc_free(splitted);
	}
}
//deallocating the list
void	ft_pop(t_node **top, int len)
{
	t_node	*trav;

	if (!top || !*top)
		return ;
	while (len--)
	{
		trav = *top;
		*top = (*top)->next;
		(*top)->prev = trav->prev;
		trav->prev->next = *top;
		if (trav)
			free(trav);
		trav = NULL;
	}
}
