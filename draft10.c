#include "get_next_line.h"

void free_all(t_list **lst) 
{
	t_list *temp;

	if (!lst)
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

static char	*get_line(t_list **lst, int len_line)
{
	t_list	*join;

	join = malloc (sizeof(t_list));
	if (!join)
	{
		free_all(lst);
		return (NULL);
	}
	join->content = malloc((len_line + 1) * sizeof(char));
	if (!join)
	{
		free_all(lst);
		return (NULL);
	}
	join->content[len_line] = '\0';
	join->next = (*lst)->next;
	(*lst)->next = join;
	return (join_content(&join));
}

static int	save_buf(char *buffer, int read_bytes, t_list **lst)
{
	t_list	*new;
	t_list	*current;

	new = ft_lstnew(buffer, read_bytes);
	if (!new)
	{
		free_all(lst);
		return (0);		
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (check_line(*lst, '\n', read_bytes));
}

static int	read_save(int fd, char *buffer, t_list *lst)
{
	int		read_bytes;
	int		len;

	read_bytes = 1;
	len = 0;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free_all(&lst), 0);
		if (read_bytes == 0 && (lst->next) != NULL)
			return(check_line(lst, '\n', read_bytes));
		buffer[read_bytes] = '\0';
		len = save_buf(buffer, read_bytes, &lst);
		if (len > 0)
			return (len);
	}
	return (0);
}


char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list	*mem;
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	int		len_line;

	//if (fd < 0 || (!lst && read(fd, buffer, BUFFER_SIZE) == 0) || (BUFFER_SIZE == 0 && !lst))
	if (fd < 0 || (BUFFER_SIZE == 0 && !lst))
		return (NULL);
	if (!lst)
	{
		if (read(fd, buffer, BUFFER_SIZE) == 0)
			return (NULL);
		else
		{
			lst = ft_lstnew(buffer, 0);
			if (!lst)
				return (NULL);
		}
	}
	len_line = read_save(fd, buffer, lst);
	if (len_line == 0)
		return (NULL);
	line = ft_strdup(get_line(&lst, len_line));
	mem = lst->next;
	lst->next = mem->next;
	free (mem->content);
	free (mem);
	if (line)
		return (line);
	else
		return (free_all(&lst), NULL);
}

