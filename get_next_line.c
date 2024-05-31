/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:45:45 by alvaro            #+#    #+#             */
/*   Updated: 2024/05/31 16:41:38y alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char *append(char *s1, char *s2) {
    size_t l1 = strlen(s1);  // Using strlen for clarity and safety
    size_t l2 = strlen(s2);
    char *ptr = malloc(l1 + l2 + 1);  // Allocate space for both strings and the null terminator
    if (ptr == NULL) return NULL;

    char *temp = ptr;  // Use a temporary pointer for manipulation to preserve the base address
    while (*s1) {
        *temp++ = *s1++;
    }
    while (*s2) {
        *temp++ = *s2++;
    }
    *temp = '\0';  // Ensure the new string is null-terminated

    return ptr;
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

char *get_next_line(int fd) {
    static char *after_eol = NULL;  // Initialize static variables to NULL if not already done
    char *complete_buffer = NULL;
    char *return_buffer = NULL;
    t_list *lst = NULL;
    int bytes_read = 0;

    if (fd < 0) return NULL;

    if (after_eol) {
        if (ft_strchr(after_eol, '\n')) {
            ft_lstadd_front(&lst, after_eol);
        } else {
            bytes_read = get_lst_from_reads(fd, &lst);
        }
    } else {
        bytes_read = get_lst_from_reads(fd, &lst);
    }

    if (bytes_read == 0 && lst == NULL) {
        return ft_strdup("", '\0');
    }

    complete_buffer = malloc(ft_lstsize(lst) * BUFF_SIZE);  // Ensure memory is allocated before using
    if (complete_buffer == NULL) return NULL;  // Handle failed allocation
    *complete_buffer = '\0';  // Initialize the buffer to be an empty string

    fill_complete_buffer(lst, &complete_buffer);

    if (ft_strchr(complete_buffer, '\n')) {
        after_eol = ft_strdup(ft_strchr(complete_buffer, '\n') + 1, '\0');
        return_buffer = ft_strdup(complete_buffer, '\n');
    } else {
        after_eol = NULL;
        return_buffer = strdup(complete_buffer);
    }

    free(complete_buffer);
    return return_buffer;
}

/*
	Si bytes_read es 0, entonces puede haber after_eol, por lo que no podemos returnear tan fácil.
	Pero se puede meter una flag para controlar ,
	
	Yo lo que quiero es generar que cuando lea 0, solo procese el after_eol. Si no hay after eol. No se puede devolver el
	after_eol porque luego lo liberas; tampoco puedes alocar memoria de si mismo, porque luego lo liberas.
	Por lo tanto, 
*/
