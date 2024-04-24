/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:43:19 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/24 13:11:13 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

#define BUFF_SIZE 128
#define FILE_PATH "/ejemplo.txt"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	*ft_strchr(const char *s, int c);
void	ft_lstadd_front(t_list **lst, char *content);
void	ft_lstadd_back(t_list **lst, char *content);
t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
