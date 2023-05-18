/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:15:47 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/24 19:15:48 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

static	int	ft_check(char c)
{
	if (c == '\n' || c == '\t' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;
	int	pre;

	sign = 1;
	res = 0;
	if (*str != '\0' && ft_check(*str) == 1)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{	
		pre = res;
		res = (res * 10) + ((*str++) - '0');
	}
	if ((pre != (res / 10)) || (*str && (!(*str >= '0' && *str <= '9'))))
		ft_error();
	return (sign * res);
}
