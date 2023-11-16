#include "get_next_line.h"
#include <stdio.h>
# include <stdlib.h>

static t_list	*lst = NULL;


void	add_lst(t_list *lst, t_list *new)
{
	t_list	*current;

	if (!lst)
		lst = new;
	else
	{
		current = lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	return ;
}
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	temp = *lst;
	*lst = new;
	new->next = temp;
}

static void free_all(t_list *lst) 
{
    while (lst) 
	{
        t_list *temp;
		
		temp = lst;
        lst = lst->next;
        free(temp->content);
        free(temp);
    }
}

char *read_check_alloc(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_bytes;
	t_list	*new;
	
	read_bytes = 1;
	while(read_bytes >= 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free_all(lst);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		new = ft_lstnew(buffer, read_bytes);
		if (!new)
		{
			free_all(lst);
			return (NULL);
		}
		if (lst == NULL)
			lst = new;
		else
			add_lst(lst, new);
		if (ft_lstchr(lst, '\n'))
		{
			new = ft_lstjoin(&lst);
			if (!new)
			{
				free_all(lst);
				return (NULL);
			}
			if (lst->next == NULL)
				lst = new->next;
			else
				ft_lstadd_front(&lst, new->next);
			return (new->content);
		}
	}
	return (NULL);
}


char	*get_next_line(int fd)
{
	char			*line;

	line = read_check_alloc(fd);
	//printf("lst->next: %p\n", lst->next);
	if (line)
		return (line);
	else
		free_all(lst);
	return (NULL);
}