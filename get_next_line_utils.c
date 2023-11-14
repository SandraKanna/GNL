/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:16:33 by skanna            #+#    #+#             */
/*   Updated: 2023/11/14 18:08:04 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list **lst)
{
	t_list	*current;

	if (!lst)
		return (NULL);
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

/*char	*ft_strchr(const char *str, int c)
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
}*/

int	lstchr(t_list **lst, int c)
{
	t_list	*current;
	int		i;
	
	i = 0;
	if (!lst)
		return (0);
	current = ft_lstlast(lst);
	while (current)
	{
		if (current->content[i] == (char)c)
			return (1);
		i++;
	}
	if (current && current->content[i] == (char)c)
		return (1);
	return (0);
}

t_list	*ft_lstnew(char *buf, int bytes)
{
	t_list	*new_node;
	int		i;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = malloc(sizeof(char) * (bytes + 1));
	if (!new_node->content)
		return (NULL);
	i = 0;
	while (i < bytes && buf[i])
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	printf("new_node: %s\n", new_node->content);
	new_node->next = NULL;
	return (new_node);
}


int	chars_in_list(t_list **lst)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		while ((*lst)->content[i])
		{
			if ((*lst)->content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		*lst = (*lst)->next;
	}
	return (len);
}

t_list	*ft_lstjoin(t_list **lst)
{
	t_list	*new_node;
	int		len_joint;
	int		i;
	int		j;
	//char	*joint;

	i = 0;
	j = 0;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	len_joint = chars_in_list(lst);
	new_node->content = malloc((len_joint + 1) * sizeof(char));
	if (!new_node->content)
	{	
		free (new_node);
		return (NULL);
	}
	while (lst)
	{
		while ((*lst)->content[i])
		{
			if ((*lst)->content[i] == '\n')
			{
				new_node->content[j++] = '\n';
				new_node->content[j] = '\0';
				return (new_node);
			}
			new_node->content[j++] = (*lst)->content[i++];
		}
		*lst = (*lst)->next;
	}
	new_node->content[j] = '\0';
	return (new_node);
}

