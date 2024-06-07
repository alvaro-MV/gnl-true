/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:37:28 by alvmoral          #+#    #+#             */
/*   Updated: 2024/06/07 18:17:00 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	read_buffer[BUFFER_SIZE];
	int		bytes_read;

	bytes_read = 1;
	ft_bzero(read_buffer, BUFFER_SIZE);
	while (bytes_read)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		//printf("bytes_readed: %i,   read_buffer: %s\n", bytes_read, read_buffer);
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
	static char	*after_eol;
	char		*complete_buffer;
	char		*return_buffer;
	t_list		*lst;
	int			bytes_read;

	if (fd < 0)
		return (NULL);
	lst = NULL;
	bytes_read = 1;
	if (after_eol != NULL)
		ft_lstadd_front(&lst, after_eol);
	if (ft_strchr(after_eol, '\n') == NULL)
		bytes_read = get_lst_from_reads(fd, &lst);
	complete_buffer = (char *) malloc(BUFFER_SIZE * ft_lstsize(lst) + 1);
	ft_bzero(complete_buffer, BUFFER_SIZE * ft_lstsize(lst) + 1);
	fill_complete_buffer(lst, complete_buffer);
	if (bytes_read == 0)
		after_eol = '\0';
	else
		after_eol = ft_strdup(ft_strchr(complete_buffer, '\n'), '\0');
	return_buffer = ft_strdup(complete_buffer, '\n');
	free(complete_buffer);
	return (return_buffer);
}
