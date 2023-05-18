/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:20:20 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/23 14:20:21 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	check_action(char *s)
{
	if (ft_strncmp(s, "sa\n", 3) == 0)
		return (1);
	if (ft_strncmp(s, "sb\n", 3) == 0)
		return (2);
	if (ft_strncmp(s, "ss\n", 3) == 0)
		return (3);
	if (ft_strncmp(s, "pa\n", 3) == 0)
		return (4);
	if (ft_strncmp(s, "pb\n", 3) == 0)
		return (5);
	if (ft_strncmp(s, "ra\n", 3) == 0)
		return (6);
	if (ft_strncmp(s, "rb\n", 3) == 0)
		return (7);
	if (ft_strncmp(s, "rr\n", 3) == 0)
		return (8);
	if (ft_strncmp(s, "rra\n", 4) == 0)
		return (9);
	if (ft_strncmp(s, "rrb\n", 4) == 0)
		return (10);
	if (ft_strncmp(s, "rrr\n", 4) == 0)
		return (11);
	return (0);
}

static void	ft_do(char *s, t_node **last, t_node **b_last)
{
	if (check_action(s) == 1)
		ft_swap_a(*last);
	else if (check_action(s) == 2)
		ft_swap_b(*b_last);
	else if (check_action(s) == 3)
		ft_swap_a_b(*last, *b_last);
	else if (check_action(s) == 4)
		ft_push_a(last, b_last);
	else if (check_action(s) == 5)
		ft_push_b(last, b_last);
	else if (check_action(s) == 6)
		ft_rotate_a(last);
	else if (check_action(s) == 7)
		ft_rotate_b(b_last);
	else if (check_action(s) == 8)
		ft_rotate_a_b(last, b_last);
	else if (check_action(s) == 9)
		ft_rev_rotate_a(last);
	else if (check_action(s) == 10)
		ft_rev_rotate_b(b_last);
	else if (check_action(s) == 11)
		ft_rev_rotate_a_b(last, b_last);
}

static void	ft_read_stdin(t_node **last, t_node **b_last)
{
	char	*s;

	if (!last || !*last)
		return ;
	s = get_next_line(0);
	while (s)
	{
		if (check_action(s) == 0)
		{
			write(1, "Error\n", 6);
			free(s);
			exit(1);
		}
		ft_do(s, last, b_last);
		free(s);
		s = NULL;
		s = get_next_line(0);
	}
}

static void	ft_fill_list(int ac, char **av)
{
	t_node	*head;
	t_node	*stack_b;
	int		begin;

	head = NULL;
	stack_b = NULL;
	ft_list_crea(ac, av, &head);
	begin = ft_size(head);
	if (ft_duplicated(head, begin) == -1)
		ft_error();
	ft_read_stdin(&head, &stack_b);
	begin = ft_size(head);
	if (ft_sorted(head, begin) == 1 && !stack_b)
		write(1, "OK\n", 3);
	else
	{
		write(1, "KO\n", 3);
		if (ft_size(stack_b) != 0)
			ft_pop(&stack_b, ft_size(stack_b));
	}
	ft_pop(&head, begin);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	else if (argc > 1)
		ft_fill_list(argc, argv);
	return (0);
}
