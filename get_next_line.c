/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:45:45 by alvaro            #+#    #+#             */
/*   Updated: 2024/04/26 12:35:35 by alvmoral         ###   ########.fr       */
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

char	*ft_strdup(char *s1, char c)
{
	char	*ptr;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	j = 0;
//	if (s1[0] == c)
//		j = 1;
	while (s1[len] && s1[len] != c)
		len++;
	ptr = (char *) malloc(len + 2);
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

int	get_lst_from_reads(int fd, t_list **lst)
{
	char	read_buffer[BUFF_SIZE];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, read_buffer, BUFF_SIZE);
		if (bytes_read == 0)
			return (0);
		ft_lstadd_back(lst, ft_strdup(read_buffer, '\0'));
		if (ft_strchr(read_buffer, '\n') != NULL)
			break ;
	}
	return (bytes_read);
}

void	fill_complete_buffer(t_list *lst, char **complete_buffer)
{
	t_list	*first_node;

	first_node = lst;
	while (lst)
	{
		*complete_buffer = append(*complete_buffer, lst->content);
		lst = lst->next;
	}
	ft_lstclear(&first_node);
}

char	*get_next_line(int fd)
{
	static char	*after_eol;
	char		*complete_buffer;
	char		*return_buffer;
	t_list		*lst;
	int			bytes_read;

	if (fd < 0)
		return (NULL);
	lst = NULL;
	complete_buffer = "";
	bytes_read = 1;
	if (after_eol != NULL)
		ft_lstadd_front(&lst, after_eol);
	if (ft_strchr(after_eol, '\n') == NULL)
		bytes_read = get_lst_from_reads(fd, &lst);
	complete_buffer = malloc(ft_lstsize(lst) * BUFF_SIZE);
	fill_complete_buffer(lst, &complete_buffer);
	after_eol = ft_strdup(ft_strchr(complete_buffer, '\n'), '\0');
	return_buffer = ft_strdup(complete_buffer, '\n');
	
	free(complete_buffer);
	return (return_buffer);
}

/*
	Si bytes_read es 0, entonces puede haber after_eol, por lo que no podemos returnear tan fácil.
	Pero se puede meter una flag para controlar ,
*/
