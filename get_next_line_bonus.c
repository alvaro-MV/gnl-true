/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:37:34 by alvmoral          #+#    #+#             */
/*   Updated: 2024/06/11 18:19:26 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/select.h>
#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
	{
		while (n--)
		{
			*(char *) s = 0;
			s++;
		}
	}
}

char	*ft_strdup(char *s1, char c)
{
	char	*ptr;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len] && s1[len] != c)
		len++;
	ptr = (char *) malloc(sizeof(char) * (len + 2));
	ft_bzero(ptr, len + 2);
	if (ptr == NULL)
		return (NULL);
	while (i < (len + 1))
	{
		ptr[i] = s1[i];
		i++;
	}
	if (s1[len] != c && len > 0)
		ptr[len] = c;
	return (ptr);
}

int	get_lst_from_reads(int fd, t_list **lst)
{
	char	read_buffer[BUFFER_SIZE];
	int		bytes_read;

	bytes_read = 1;
	ft_bzero(read_buffer, BUFFER_SIZE);
	while (bytes_read)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (0);
		read_buffer[bytes_read] = '\0';
		ft_lstadd_back(lst, ft_strdup(read_buffer, '\0'));
		if (ft_strchr(read_buffer, '\n') != NULL)
			break ;
	}
	return (bytes_read);
}

void	fill_complete_buffer(t_list *lst, char *complete_buffer)
{
	t_list	*first_node;
	char	*lst_content;
	int		i;

	i = 0;
	first_node = lst;
	while (lst)
	{
		lst_content = lst->content;
		while (*lst_content)
		{
			complete_buffer[i] = *lst_content;
			i++;
			lst_content++;
		}
		lst = lst->next;
	}
	ft_lstclear(&first_node);
}

char	*get_next_line(int fd)
{
	static char	*after_eol[FD_SETSIZE];
	char		*complete_buffer;
	char		*return_buffer;
	t_list		*lst;
	int			bytes_read;

	if (fd < 0)
		return (NULL);
	lst = NULL;
	bytes_read = 1;
	if (after_eol[fd] != NULL)
		ft_lstadd_front(&lst, after_eol[fd]);
	if (ft_strchr(after_eol[fd], '\n') == NULL)
		bytes_read = get_lst_from_reads(fd, &lst);
	complete_buffer = (char *) malloc(BUFFER_SIZE * ft_lstsize(lst) + 2);	
	ft_bzero(complete_buffer, BUFFER_SIZE * ft_lstsize(lst) + 2);
	fill_complete_buffer(lst, complete_buffer);
	if (bytes_read == 0)
		after_eol[fd] = "";
	else
		after_eol[fd] = ft_strdup(ft_strchr(complete_buffer, '\n'), '\0');
	return_buffer = ft_strdup(complete_buffer, '\n');
	free(complete_buffer);
	return (return_buffer);
}