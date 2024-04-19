/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:45:45 by alvaro            #+#    #+#             */
/*   Updated: 2024/04/19 15:19:29by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append(char *s1, char *s2)
{
	char    *ptr;
	size_t  l1;
	size_t  l2;
	size_t  lt;

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
	free(s2);
	return (ptr - lt);
}

char    *ft_strdup(const char *s1)
{
        char	*ptr;
        int		len;
		int		i;

        len = 0;
		i = 0;
        while (s1[len])
                len++;
		len++;
        ptr = (char *) malloc(len + 1);
        if (ptr == NULL)
                return (NULL);
        while (len--)
        {
            ptr[i] = s1[i];
            i++;
        }
        return (ptr);
}

char	*get_next_line(int fd)
{
	int 		found;
	static char	*after_eol;
	char		read_buffer[BUFF_SIZE];
	char		*return_buffer;
	t_list		*lst;

	if (fd < 0)
		return (NULL);
	found = 0;
	lst = NULL;
	after_eol = NULL;
	while (!found)
	{
		if (found == 1)
		{
			return_buffer = (after_eol, return_buffer);
			found == 1;
		}
		read(fd, read_buffer, BUFF_SIZE);
		if (ft_strchr(read_buffer, '\n') == NULL)
			ft_lstadd_back(&lst, ft_lstnew(ft_strdup(read_buffer)));
		else
		{
			return_buffer = malloc(ft_lstsize(lst) * BUFF_SIZE);
			while(lst)
			{
				return_buffer = append(lst->content, return_buffer);
				lst->next;
			}
			ft_lstclear(&lst);
			after_eol = ft_strchr(read_buffer, '\n'); //quiza haya que alocar memoria.
			found = 1;
		}
	}
	return (return_buffer);
}

