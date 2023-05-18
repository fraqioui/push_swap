/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:54:58 by fraqioui          #+#    #+#             */
/*   Updated: 2022/11/01 11:03:19 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	*get_next_line(int fd)
{
	static char	*from;
	char		*buf;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&from, NULL));
	s = ft_get_the_line(fd, &from, buf);
	free(buf);
	if (!s)
		return (ft_free(&from, NULL));
	return (s);
}

char	*ft_get_the_line(int fd, char **str, char *buf)
{
	ssize_t	b_read;
	char	*s;

	b_read = read(fd, buf, BUFFER_SIZE);
	while (b_read >= 0)
	{
		buf[b_read] = '\0';
		s = ft_strjoin(*str, buf);
		ft_free(str, s);
		if (ft_check_new_line(*str) != -1)
			return (ft_new_line(str));
		if (!b_read && ft_strlen(*str) > 0)
			return (ft_save(str, 0));
		if (!**str && !b_read)
			return (ft_free(str, NULL));
		b_read = read(fd, buf, BUFFER_SIZE);
	}
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_free(char **s, char *set)
{
	free(*s);
	*s = set;
	return (*s);
}

char	*ft_new_line(char **s2)
{
	char	*str;
	size_t	j;

	j = ft_check_new_line(*s2);
	str = ft_substr(*s2, 0, j + 1);
	*s2 = ft_save(s2, j + 1);
	return (str);
}

char	*ft_save(char **s3, size_t n)
{
	size_t	l;
	char	*save;

	l = ft_strlen(*s3 + n);
	save = ft_substr(*s3, n, l);
	free(*s3);
	*s3 = NULL;
	return (save);
}
