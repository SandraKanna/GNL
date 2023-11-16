/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:12:39 by skanna            #+#    #+#             */
/*   Updated: 2023/11/16 23:15:09 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void free_all(t_list *lst) 
{
	while (lst) 
	{
		t_list *temp;
		
		temp = lst->next;
		free(lst->content);
		free(lst);
		lst = temp;
	}
}

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
	new_node->next = NULL;
	return (new_node);
}

int	check_line(t_list *lst, char c)
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
			if (lst->content[i] == c)
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		lst = lst->next;
	}
	len = 0;
	return (len);
}

char	*join_content(t_list *lst)
{
	t_list	*first;
	int		i;
	int		j;
	
	first = lst->next;
	i = 0;
	j = 0;
	while (first->next->content[i] != '\n')
	{	
		first->content[j] = first->next->content[i];
		if (first->next->content[++i] == '\0')
		{
			first->next = first->next->next;
			free (first->next->content);
			free (first->next);
			i = 0;
		}
		j++;
	}
	first->content[j++] = '\n';
	first->content[j] = '\0';
	i++;
	j = 0;
	while (first->next->content[i] != '\0')	
		first->next->content[j++] = first->next->content[i++];
	first->next->content[j] = '\0';
	return (first->content);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len_s;
	int		i;

	i = 0;
	len_s = 0;
	while (s[len_s])
		len_s++;
	dup = malloc((len_s + 1) * sizeof(const char));
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = ((char *)s)[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
