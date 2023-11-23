/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:12:39 by skanna            #+#    #+#             */
/*   Updated: 2023/11/23 18:31:21 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_all(t_list **lst)
{
	t_list	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

static char	*get_line(t_list **lst, char *line)
{
	t_list	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*lst && (*lst)->content[i] != '\n')
	{
		line[j++] = (*lst)->content[i++];
		if ((*lst)->content[i] == '\0')
		{
			temp = (*lst)->next;
			free ((*lst)->content);
			free (*lst);
			*lst = temp;
			i = 0;
		}
	}
	if ((*lst) && (*lst)->content[i++] == '\n')
		line[j] = '\n';
	check_rest(lst, i);
	return (line);
}

static int	save_buffer(t_list **lst, t_list *new, int read_bytes)
{
	t_list	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (check_line(*lst, '\n', read_bytes));
}

static int	check_read(int fd, char *buffer, t_list **lst)
{
	int		b_read;
	t_list	*new;
	int		len_line;

	b_read = 1;
	len_line = 0;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read < 0 || (b_read == 0 && *lst == NULL))
			return (-1);
		if (b_read == 0 && *lst != NULL)
			return (check_line(*lst, '\n', b_read));
		if (b_read > 0)
		{
			buffer[b_read] = '\0';
			new = ft_lstnew(buffer, b_read);
			len_line = save_buffer(lst, new, b_read);
			if (len_line > 0)
				return (len_line);
		}
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static t_list	*lst[1024];
	char			*line;
	char			buffer[BUFFER_SIZE + 1];
	int				len_line;

	if (fd < 0 || (BUFFER_SIZE == 0 && !lst[fd]))
		return (NULL);
	len_line = check_read(fd, buffer, &(lst[fd]));
	if (len_line < 0)
	{
		free_all (&(lst[fd]));
		return (NULL);
	}
	line = malloc(sizeof(char) * (len_line + 1));
	if (!line)
	{
		free_all (&(lst[fd]));
		return (NULL);
	}
	line[len_line] = '\0';
	get_line(&(lst[fd]), line);
	return (line);
}
