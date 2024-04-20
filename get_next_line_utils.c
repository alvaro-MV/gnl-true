/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:47:09 by alvaro            #+#    #+#             */
/*   Updated: 2024/04/20 21:32:44 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	c = (char) c;
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	if (*s == c)
		return ((char *) s);
	else
		return (0);
}

void	ft_lstadd_front(t_list **lst, char *content)
{
	t_list	*list;
	t_list	*new_n;

	new_n = (t_list *) malloc(sizeof(t_list));
	if (new_n == NULL)
		return ;
	new_n->content = content;
	new_n->next = NULL;
	list = *lst;
	new_n->next = list;
	*lst = new_n;
}

void	ft_lstadd_back(t_list **lst, char *content)
{
	t_list	*list;
	t_list	*holder;
	t_list	*new_n;

	new_n = (t_list *) malloc(sizeof(t_list));
	if (new_n == NULL)
		return ;
	new_n->content = content;
	new_n->next = NULL;
	list = *lst;
	if (list == NULL)
		*lst = new_n;
	if (list != NULL)
	{
		while (list != NULL)
		{
			holder = list;
			list = list->next;
		}
		holder->next = new_n;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*holder;
	t_list	*list;

	list = *lst;
	while (list != NULL)
	{
		holder = list;
		list = list->next;
		free(holder->content);
		free(holder);
	}
	*lst = NULL;
}

int	ft_lstsize(t_list *lst)
{
	int	contador;

	contador = 0;
	while (lst != NULL)
	{
		contador++;
		lst = lst->next;
	}
	return (contador);
}
