/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:55:34 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/24 18:40:43 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	void	ft_fill_list(int ac, char **av)
{
	t_node	*head;
	int		begin;

	head = NULL;
	//list creation
	ft_list_crea(ac, av, &head);
	//calculate the size of the list
	begin = ft_size(head);
	//check if there is any duplicate number
	if (ft_duplicated(head, begin) == -1)
		ft_error();
	//check if stack a is already sorted
	if (ft_sorted(head, begin) == 1)
	{
		ft_pop(&head, begin);
		return ;
	}
	begin = ft_size(head);
	//algo of three numbers
	if (begin <= 3)
		ft_algo_of_three(&head, begin);
	//algo of five numbers
	else if (begin > 3 && begin <= 5)
		ft_algo_of_five(&head, begin);
	//main algo
	else if (begin > 5)
		ft_algo_lis(&head, begin);
	//deallocate the list before terminating
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
