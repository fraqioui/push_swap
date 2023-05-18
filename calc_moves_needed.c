/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves_needed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:00:10 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/24 18:34:19 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_apply_moves_b(t_node **stack_a, t_node **stack_b, int len)
{
	t_node	*trav;
	int		i;
	int		l;

	trav = *stack_a;
	i = 0;
	l = 0;
	while (i < len)
	{
		trav = trav->next;
		if (trav->n_moves == 0)
		{
			l++;
			if (trav->index != 0)
				ft_into_action(stack_a, trav->index);
			ft_push_b(stack_a, stack_b);
			write(1, "pb\n", 3);
			i = -1;
			len--;
			ft_indexing(*stack_a, len);
			trav = *stack_a;
		}
		i++;
	}
	ft_indexing(*stack_b, l);
}
//looking for the position of stack b's element in stack a
static	int	ft_find_pos(t_node *head, t_node *to_sear, int len)
{
	if (head->prev->data < to_sear->data || head->data > to_sear->data)
		return (head->index);
	while (len--)
	{
		if (to_sear->data > head->data && to_sear->data < head->next->data)
			break ;
		head = head->next;
	}
	return (head->next->index);
}

static	void	ft_save_posi(t_node *b)
{
	if (b->index < 0)
	{
		if (b->index < b->pos_a)
			b->n_moves = -1 * b->index;
		else
			b->n_moves = -1 * b->pos_a;
	}
	else if (b->index > 0)
	{
		if (b->index > b->pos_a)
			b->n_moves = b->index;
		else
			b->n_moves = b->pos_a;
	}
}

static	void	ft_save_neg(t_node *b)
{
	if (b->index < 0 && b->pos_a >= 0)
		b->n_moves = -1 * b->index + b->pos_a;
	else if (b->pos_a < 0 && b->index >= 0)
		b->n_moves = -1 * b->pos_a + b->index;
	else if (b->index == 0 && b->pos_a)
		b->n_moves = b->pos_a;
	else if (b->pos_a == 0 && b->index > 0)
		b->n_moves = b->index;
}
//calculate the moves needed by an element in stack b to be in its right place in stack a.
void	ft_moves_calc(t_node *stack_a, t_node *stack_b, int len_a, int len_b)
{
	t_node	*min;

	min = ft_min_node(stack_a, len_a);
	while (len_b--)
	{
		stack_b = stack_b->next;
		stack_b->pos_a = ft_find_pos(min, stack_b, len_a);
		if ((stack_b->pos_a) * (stack_b->index) > 0)
			ft_save_posi(stack_b);
		else if ((stack_b->pos_a) * (stack_b->index) <= 0)
			ft_save_neg(stack_b);
	}
}
