#include "get_next_line.h"
#include <stdio.h>

/*static int	chars_in_line(char *buf, int read_bytes)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && i < read_bytes)
		i++;
	if (buf[i] == '\n')
		i++;
	return (i);
}*/

void	add_lst(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;	
	}
	return ;
}

char	*ft_alloc_lsts(int fd, char *buffer, t_list **lst)
{
	int		bytes_read;
	t_list	*new;

	bytes_read = 1;
	while (bytes_read > 0 && buffer)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!ft_strchr(buffer, '\n'))
		{	
			new = ft_lstnew(buffer, bytes_read);
			if (!new)
				return(NULL);
			add_lst(lst, new);
		}
		else
		{	
			new = ft_lstjoin(*lst);
			if (!new)
				return(NULL);
			add_lst(lst, new);
		}		
	}
	return ((*lst)->content);
}

void free_lst(t_list *lst)
{
    while (lst)
    {
        t_list *temp = lst;
        lst = lst->next;
        free(temp->content);
        free(temp);
    }
}


char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;
	char			*buffer;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{	
		free_lst(lst); 
		return (NULL);
	}
	line = ft_alloc_lsts(fd, buffer, &lst);
	free (buffer);
	printf("lst content: %s\n", lst->content);
	printf("line: %s\n", line);

	while (lst)
	{
        t_list *temp = lst;
        lst = lst->next;
        free(temp->content);
        free(temp);
    }
	return (line);
}
 

