/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:16:33 by skanna            #+#    #+#             */
/*   Updated: 2023/11/16 22:03:33 by skanna           ###   ########.fr       */
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
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstchr(t_list *lst, char c)
{
//	t_list	*current;
	int		i;
	
	if (!lst)
		return (0);
	// current = ft_lstlast(lst);
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == c)
				return (1);
			i++;
		}
		if (lst && lst->content[i] == c)
			return (1);
		lst = lst->next;
	}
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
static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	chars_in_line(t_list *lst)
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

t_list	*ft_lstjoin(t_list **lst)
{
	t_list	*new_node;
	t_list *temp;
	t_list	*res;
	int		len_joint;
	int		i;
	int		j;

	j = 0;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	len_joint = chars_in_line(*lst);
	new_node->content = malloc((len_joint + 1) * sizeof(char));
	if (!new_node->content)
	{	
		free (new_node);
		return (NULL);
	}
	while (lst)
	{
		i = 0;
		//check \n in first node so we can free it
		while ((*lst)->content[i])
		{
			if ((*lst)->content[i] == '\n')
			{
				new_node->content[j++] = '\n';
				new_node->content[j] = '\0';
				i++;
				if ((*lst)->content[i] != '\0')
				{
					res = ft_lstnew((((*lst)->content) + i), (ft_strlen((*lst)->content) - i));
					new_node->next = res;
				}
				else
					new_node->next = NULL;
				return (new_node);
			}
			new_node->content[j++] = (*lst)->content[i++];
		}
		temp = (*lst)->next;
		free ((*lst)->content);
		free ((*lst));
		*lst = temp;
	}
	new_node->content[j] = '\0';
	new_node->next = NULL;
	return (new_node);
}

