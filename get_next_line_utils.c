/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:55:28 by fraqioui          #+#    #+#             */
/*   Updated: 2022/11/01 11:12:35 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

size_t	ft_strlen(const char *s)
{
	const char	*end;

	end = s;
	while (*end)
		end++;
	return (end - s);
}

ssize_t	ft_check_new_line(char *s1)
{
	ssize_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(const char *s)
{
	char	*arr;
	size_t	n;
	int		i;

	n = ft_strlen(s);
	i = 0;
	arr = malloc(sizeof(char) * (n + 1));
	if (!arr)
		return (NULL);
	while (n--)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1)
		str = ft_strdup("");
	else
		str = ft_strdup(s1);
	ptr = (char *)malloc((ft_strlen(str) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
	{
		free(str);
		return (0);
	}
	while (str[++i])
		ptr[i] = str[i];
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(str);
	return (ptr);
}

char	*ft_substr(char *s, unsigned int index, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (index >= s_len)
		return (ft_strdup(""));
	if (s_len <= len + index)
		substr = malloc(sizeof(char) * (s_len - index + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[index] && i < len)
	{
		substr[i] = s[index + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
