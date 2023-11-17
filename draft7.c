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

static char	*get_line(t_list *lst, int len_line)
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
	join->next = lst->next;
	lst->next = join;
	return (join_content(&join));
}

static int	save_buf(char *buffer, int read_bytes, t_list *lst)
{
	t_list	*new;
	t_list	*current;

	new = ft_lstnew(buffer, read_bytes);
	if (!new)
	{
		free_all(lst);
		return (0);		
	}
	current = lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (check_line(lst, '\n'));
}

static int	read_save(int fd, char *buffer, t_list *lst)
{
	int		read_bytes;
	int		i;
	int		len;

	read_bytes = 1;
	len = 0;
	i = 0;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0)
		{
			while (buffer[i])
				buffer[i++] = '\0';
			return (0);
		}
		if (read_bytes < 0)
			return (free_all(lst), 0);
		buffer[read_bytes] = '\0';
		len = save_buf(buffer, read_bytes, lst);
		if (len > 0)
			return (len);
	}
	return (len);
}


char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list	*mem;
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	int		len_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!lst)
	{
		lst = ft_lstnew("", 0);
		if (!lst)
			return (NULL);
	}
	len_line = read_save(fd, buffer, lst);
	line = ft_strdup(get_line(lst, len_line));
	mem = lst->next;
	free (lst->next->content);
	lst->next = mem->next;
	free (mem);
	if (line)
		return (line);
	else
		return (free_all(lst), NULL);
}
