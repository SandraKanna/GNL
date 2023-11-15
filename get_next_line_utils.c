/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:16:33 by skanna            #+#    #+#             */
/*   Updated: 2023/11/15 19:09:37 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_list	*ft_lstnew(char *buf, int bytes)
{
	t_list	*new_node;
	int		i;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content =	 malloc(sizeof(char) * (bytes + 1));
	if (!new_node->content)
	{
		free (new_node);
		return (NULL);
	}
	i = 0;
	while (i < bytes && buf[i])
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[bytes] = '\0';
	//printf("new_node: %s\n", new_node->content);
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstchr(t_list *lst, char c)
{
	t_list	*current;
	int		i;
	
	i = 0;
	if (!lst)
		return (0);
	current = ft_lstlast(lst);
	while (current->content[i])
	{
		if (current->content[i] == c)
			return (1);
		i++;
	}
	if (current && current->content[i] == c)
		return (1);
	return (0);
}

/*char	*ft_strchr(char *str, int c)
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

static int	chars_in_list(t_list *lst)
{
	int	i;
	int	len;

	len = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

t_list	*ft_lstjoin(t_list *lst)
{
	t_list	*new_node;
	t_list *temp;
	t_list	*res;
	int		len_joint;
	int		i;
	int		j;
	//char	*joint;


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
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				new_node->content[j++] = '\n';
				new_node->content[j] = '\0';
				if (lst->content[i + 1] != '\0')
				{
					res = ft_lstnew(((lst->content) + i + 1), BUFFER_SIZE - (i + 1));
					new_node->next = res;
				}
				else
					new_node->next = NULL;
				return (new_node);
			}
			new_node->content[j++] = lst->content[i++];
		}
		temp = lst;
		lst = lst->next;
		free (temp->content);
		free (temp);
	}
	new_node->content[j] = '\0';
	new_node->next = NULL;
	return (new_node);
}

