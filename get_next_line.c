/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:45:45 by alvaro            #+#    #+#             */
/*   Updated: 2024/04/20 20:06:38by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*append(char *s1, char *s2)
{
	char	*ptr;
	size_t	l1;
	size_t	l2;
	size_t	lt;

	l1 = 0;
	while (s1[l1])
		l1++;
	l2 = 0;
	while (s2[l2])
		l2++;
	lt = l1 + l2;
	ptr = (char *) malloc(lt * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	free(s1 - l1);
	return (ptr - lt);
}

char	*ft_strdup(const char *s1, char c)
{
	char	*ptr;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	j = 0;
	if (s1[0] == c)
		j = 1;
	while (s1[len] && s1[len] != c)
		len++;
	ptr = (char *) malloc(len + j + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < (len + 1))
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*after_eol;
	char		read_buffer[BUFF_SIZE];
	char		*return_buffer;
	t_list		*lst;
	t_list		*first_node;

	if (fd < 0)
		return (NULL);
	lst = NULL;
	return_buffer = "";
	if (after_eol != NULL)
		ft_lstadd_front(&lst, after_eol);
	if (ft_strchr(after_eol, '\n') == NULL)
	{
		while (read(fd, read_buffer, BUFF_SIZE - 2))
		{
			ft_lstadd_back(&lst, ft_strdup(read_buffer, '\0'));
			if (ft_strchr(read_buffer, '\n') != NULL)
				break ;
		}
	}
	return_buffer = malloc(ft_lstsize(lst) * BUFF_SIZE);
	first_node = lst;
	while (lst)
	{
		return_buffer = append(return_buffer, lst->content);
		lst = lst->next;
	}
	ft_lstclear(&first_node);
	after_eol = ft_strdup(ft_strchr(return_buffer, '\n'), '\0');
	return_buffer = ft_strdup(return_buffer, '\n');
	return (return_buffer);
}
