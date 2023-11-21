/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:12:39 by skanna            #+#    #+#             */
/*   Updated: 2023/11/21 19:18:53 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		free (new_node->content);
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

int	check_line(t_list *lst, char c, int read_bytes)
{
	int	i;
	int	len;

	len = 0;
	if (!lst)
		return (-1);
	while (lst != NULL)
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
	if (read_bytes > 0)
		return (0);
	return (len);
}
void	check_rest(t_list **lst, int i)
{
	int	j;
	
	j = 0;
	if ((*lst) && (*lst)->content[i] == '\0')
	{	
		free_all(lst);
		return ;
	}
	while ((*lst) && (*lst)->content[i] != '\0')
		(*lst)->content[j++] = (*lst)->content[i++];
	if (*lst)
		(*lst)->content[j] = '\0';
	return ;
}

/*void	manage_line(t_list **join, int i)
{
	int		j;
	t_list	*temp;

	j = 0;
	
	if ((*join)->next == NULL)
		return ;
	if ((*join)->next->content[i] == '\0')
	{
		temp = (*join)->next->next;
		free ((*join)->next->content);
		free ((*join)->next);			
		(*join)->next = temp;
	}
	else
	{
		while ((*join)->next->content[i] != '\0')
			(*join)->next->content[j++] = (*join)->next->content[i++];
		(*join)->next->content[j] = '\0';
	}
	return ;
	//return ((*join)->content);
}

char	*join_content(t_list **join)
{
	int		i;
	int		j;
	t_list	*temp;
	
	i = 0;
	j = 0;
	while ((*join)->next != NULL && (*join)->next->content[i] != '\n')
	{
		(*join)->content[j++] = (*join)->next->content[i++];
		if ((*join)->next->content[i] == '\0')
		{
			temp = (*join)->next->next;
			free ((*join)->next->content);
			free ((*join)->next);
			(*join)->next = temp;
			i = 0;
		}
	}
	if ((*join)->next != NULL && (*join)->next->content[i++] == '\n')
		(*join)->content[j] = '\n';
	manage_line(join, i);
	return((*join)->content);
}*/

/*char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 ||!s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joint = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (joint == NULL)
		return (NULL);
	while (s1[j])
		joint [i++] = ((char *)s1)[j++];
	j = 0;
	while (s2[j])
		joint[i++] = ((char *)s2)[j++];
	joint[i] = '\0';
	return (joint);
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
}*/
