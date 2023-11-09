/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:16:33 by skanna            #+#    #+#             */
/*   Updated: 2023/11/09 18:09:30 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
t_list	*ft_lstnew(char *buf, int bytes)
{
	t_list	*new_node;
	int		i;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = malloc (sizeof(char) * (bytes + 1));
	if (!new_node->content)
		return (NULL);
	i = 0;
	while (buf)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstnew_n(char *buf, int bytes)
{
	t_list	*new_node;
	int		i;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = malloc (sizeof(char) * (bytes + 1));
	if (!new_node->content)
		return (NULL);
	i = 0;
	while (buf[i])
	{
		while (buf[i] != '\n')
		{
			new_node->content[i] = buf[i];
			i++;
		}
		new_node->content[i++] = '\n';
		new_node->content[i] = '\0';
		new_node->next = NULL;
	}
	return (new_node);
}



void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}


t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}


