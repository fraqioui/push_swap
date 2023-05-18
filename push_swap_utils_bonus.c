/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:10:15 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/23 15:10:17 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	s1_l;
	size_t	s2_l;
	size_t	i;
	size_t	j;

	if (!(s1 || s2))
		return (0);
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	i = 0;
	j = 0;
	while (i <= s1_l && j <= s2_l && n--)
	{
		if (s1[i] != s2[j])
			return ((unsigned char) s1[i] - s2[j]);
		i++;
		j++;
	}
	return (0);
}
